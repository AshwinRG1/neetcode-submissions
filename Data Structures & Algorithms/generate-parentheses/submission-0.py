class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        path = []

        def validParenthesis(s):
            st = []
            for char in s:
                if char == '(':
                    st.append(char)
                elif char == ')':
                    if not st:
                        return False
                    st.pop()
            return len(st) == 0

        def backtrack(count):
            if count == 2 * n:
                if validParenthesis(path):
                    res.append("".join(path))
                return

            path.append('(')
            backtrack(count + 1)
            path.pop()

            path.append(')')
            backtrack(count + 1)
            path.pop()

        backtrack(0)
        return res