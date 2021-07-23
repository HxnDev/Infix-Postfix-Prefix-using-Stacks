# Infix-Postfix-Prefix-using-Stacks

# CS 201/218 DATA STRUCTURES

## Assignment # 0 3

## Task 1

One of the tasks that compilers and interpreters must frequently perform is deciding whether
some pairs of expression delimiters are properly paired, even if they are embedded multiple
pairs deep. Consider the following C++ expression.
a = (f[b] — (c+d)) / 2;
The compiler has to be able to determine which pairs of opening and closing delimiters—
parentheses, square braces, etc.—go together and whether the whole expression is correctly
delimited. Several possible errors can occur because of unpaired delimiters or because of
improperly placed delimiters. For instance, the expression below lacks a closing parenthesis.
a = (f[b] — (c+d) / 2;


The following expression is also invalid. There are the correct numbers of parenthesis and
braces, but they are not correctly balanced. The first closing parenthesis does not match the
most recent opening delimiter, a brace.
a = (f[b) — (c+d]) / 2;
A stack is extremely helpful in implementing solutions to this type of problem because of its
LIFO—Last In, First Out—behavior. A closing delimiter must correctly match the most recently
encountered opening delimiter. This is handled by pushing opening delimiters onto a stack as
they are encountered. When a closing delimiter is encountered, it should be possible to pop the
matching opening delimiter off the stack. If it is determined that every closing delimiter had a
matching opening delimiter, then the expression is valid.

### bool delimitersOk( const string expression )

Results:
Returns true if all the parentheses and braces in the string are legally paired. Otherwise, returns
false.
Note: All three type of parentheses ([ ],{ }, ( )) should be checked.

```
Test Plan (delimitersOk operation)
Test case Commands Expected result
Valid expression with
parentheses
Valid expression with
mixed delimiters
Invalid expression with
mixed delimiters
Empty expression
Improperly paired brace
```
```
3 * (a+b)
```
```
F[3 * (a+b)]
```
```
(f[b) – (c+d]/2;
Empty string
a = f [ + 3
```
```
true
```
```
true
```
```
false
false
false
```
## Task 2

We commonly write arithmetic expressions in infix form, that is, with each operator placed
between its operands, as in the following expression:
(3 + 4) * (5 / 2)
Although we are comfortable writing expressions in this form, infix form has the disadvantage
that parentheses must be used to indicate the order in which operators are to be evaluated.
These parentheses, in turn, greatly complicate the evaluation process.
Evaluation is much easier if we can simply evaluate operators from left to right. Unfortunately,
this evaluation strategy will not work with the infix form of arithmetic expressions. However, it
will work if the expression is in postfix form. In the postfix form of an arithmetic expression,
each operator is placed immediately after its operands. The expression above is written in
postfix form as
3 4 + 5 2 / *


Note that both forms place the numbers in the same order (reading from left to right). The
order of the operators is different, however, because the operators in the postfix form are
positioned in the order in which they are evaluated. The resulting postfix expression is hard to
read at first, but it is easy to evaluate. All you need is a stack on which to place intermediate
results.

### string InfixToPostfix(const string str)

```
Test Plan (infix to postfix conversion)
Test case (Arithmetic
expression)
Post fix expression Expected result
```
```
(3 + 4) * (5 / 2)
2 + 12 / 6
A + B * C – ( D / E + F $ G $ H )
```
#### 3 4 + 5 2 / *

#### 2 12 6 / +

#### A B C * + D E / F G $ H $ + -

Note: only binary operators (+,-,*,/, $(power)) allowed.

### T PostfixEvaluation(const string str) // T mean int, double & float

```
Test Plan (postfix arithmetic expression evaluation)
Test case Arithmetic expression Expected result Checked
```
```
One operator
Nested operators
Uneven nesting
All operators at end
Zero dividend
Single-digit number
```
#### 34+

#### 34+52/*

#### 93*2+1-

#### 4675 - +*

#### 02/

#### 7

#### 7

#### 14

#### 28

#### 32

```
error
7
```

