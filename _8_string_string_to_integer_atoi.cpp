#include <iostream>
#include <string>

using namespace std;

// Hua Hua
class Solution {
public:
  int myAtoi(const string &s) {
    long long ans = 0;
    int neg = 0;
    int pos = 0;
    bool p = false; // has '.'
    bool a = false; // has letters
    bool n = false; // has number

    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == ' ') {
        if (n || neg || pos)
          break;
      } else if (s[i] == '-') {
        if (n)
          break;
        else
          neg++;
      } else if (s[i] == '+') {
        if (n)
          break;
        else
          pos++;
      } else if (s[i] == '.')
        p = true;
      else if (s[i] >= '0' && s[i] <= '9' && !p && !a) {
        ans = ans * 10 + (s[i] - '0');
        n = true;
      } else {
        a = true;
      }
      if (ans / 10 > INT_MAX)
        break; // ans can be > 64 bit
    }

    if (neg)
      ans = -ans;

    if (ans > INT_MAX)
      ans = INT_MAX;
    if (ans < INT_MIN)
      ans = INT_MIN;

    if (pos + neg > 1)
      ans = 0;

    return ans;
  }
};

// Follow the Rules, Leetcode
class Solution2 {
public:
  int myAtoi(string input) {
    int sign = 1;
    int result = 0;
    int index = 0;
    int n = input.size();

    // Discard all spaces from the beginning of the input string.
    while (index < n && input[index] == ' ') {
      index++;
    }

    // sign = +1, if it's positive number, otherwise sign = -1.
    if (index < n && input[index] == '+') {
      sign = 1;
      index++;
    } else if (index < n && input[index] == '-') {
      sign = -1;
      index++;
    }

    // Traverse next digits of input and stop if it is not a digit.
    // End of string is also non-digit character.
    while (index < n && isdigit(input[index])) {
      int digit = input[index] - '0';

      // Check overflow and underflow conditions.
      if ((result > INT_MAX / 10) ||
          (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
        // If integer overflowed return 2^31-1, otherwise if underflowed return
        // -2^31.
        return sign == 1 ? INT_MAX : INT_MIN;
      }

      // Append current digit to the result.
      result = 10 * result + digit;
      index++;
    }

    // We have formed a valid number without any overflow/underflow.
    // Return it after multiplying it with its sign.
    return sign * result;
  }
};

// Deterministic Finite Automation (DFA), Leetcode
enum State { q0, q1, q2, qd };

class StateMachine {
  // Store current state value.
  State currentState;
  // Store result formed and it's sign.
  int result, sign;

  // Transition to state q1.
  void toStateQ1(char &ch) {
    sign = (ch == '-') ? -1 : 1;
    currentState = q1;
  }

  // Transition to state q2.
  void toStateQ2(int digit) {
    currentState = q2;
    appendDigit(digit);
  }

  // Transition to dead state qd.
  void toStateQd() { currentState = qd; }

  // Append digit to result, if out of range return clamped value.
  void appendDigit(int &digit) {
    if ((result > INT_MAX / 10) ||
        (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
      if (sign == 1) {
        // If sign is 1, clamp result to INT_MAX.
        result = INT_MAX;
      } else {
        // If sign is -1, clamp result to INT_MIN.
        result = INT_MIN;
        sign = 1;
      }

      // When the 32-bit int range is exceeded, a dead state is reached.
      toStateQd();
    } else {
      // Append current digit to the result.
      result = result * 10 + digit;
    }
  }

public:
  StateMachine() {
    currentState = q0;
    result = 0;
    sign = 1;
  }

  // Change state based on current input character.
  void transition(char &ch) {
    if (currentState == q0) {
      // Beginning state of the string (or some whitespaces are skipped).
      if (ch == ' ') {
        // Current character is a whitespaces.
        // We stay in same state.
        return;
      } else if (ch == '-' || ch == '+') {
        // Current character is a sign.
        toStateQ1(ch);
      } else if (isdigit(ch)) {
        // Current character is a digit.
        toStateQ2(ch - '0');
      } else {
        // Current character is not a space/sign/digit.
        // Reached a dead state.
        toStateQd();
      }
    } else if (currentState == q1 || currentState == q2) {
      // Previous character was a sign or digit.
      if (isdigit(ch)) {
        // Current character is a digit.
        toStateQ2(ch - '0');
      } else {
        // Current character is not a digit.
        // Reached a dead state.
        toStateQd();
      }
    }
  }

  // Return the final result formed with it's sign.
  int getInteger() { return sign * result; }

  // Get current state.
  State getState() { return currentState; }
};

class Solution3 {
public:
  int myAtoi(string s) {
    StateMachine Q;

    for (int i = 0; i < s.size() && Q.getState() != qd; ++i) {
      Q.transition(s[i]);
    }

    return Q.getInteger();
  }
};

int main() {
  string s1 = "42";
  string s2 = "     -42";
  string s3 = "4193 with words 22";
  string s4 = "with words 3215";
  string s5 = "  123.45"; // We will not print out the digits after '.'

  Solution sol;
  auto res = sol.myAtoi(s1);
  auto res2 = sol.myAtoi(s2);
  auto res3 = sol.myAtoi(s3);
  auto res4 = sol.myAtoi(s4);
  auto res5 = sol.myAtoi(s5);

  cout << res << endl;
  cout << res2 << endl;
  cout << res3 << endl;
  cout << res4 << endl;
  cout << res5 << endl;

  return 0;
}