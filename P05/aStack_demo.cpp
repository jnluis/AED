//
// Tomás Oliveira e Silva, AED, November 2021
//
// matched-parenthesis verification
//

#include <iostream>
#include "aStack.h"

using std::cerr;
using std::cout;
using std::endl;

int check_parenthesis(const char *s)
{
  aStack<int> stack;
  // put your code here (20 lines of code should be enough)
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (s[i] == '(')
    {
      stack.push(i);
    }
    else if (s[i] == ')')
    {
      if (stack.size() > 0)
      {
        printf("'(' at position %i and matching ')' at position %i \n", stack.pop(), i);
      }
      else
      {
        printf("unmatched ')' at position %i\n", i);
        return -1;
      }
    }
  }

  if (stack.is_empty())
    return 0; // good
  else
    while (!stack.is_empty())
      printf("unmatched ')' at position %i\n", stack.pop());
  return -1;
}

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    cerr << "usage: " << argv[0] << " [arguments...]" << endl;
    cerr << "example: " << argv[0] << " 'abc(def)ghi' 'x)(y'" << endl;
    return 1;
  }
  for (int i = 1; i < argc; i++)
  {
    cout << argv[i] << endl;
    if (check_parenthesis(argv[i]) == 0)
      cout << "  good" << endl;
    else
      cout << "  bad" << endl;
  }
  return 0;
}
