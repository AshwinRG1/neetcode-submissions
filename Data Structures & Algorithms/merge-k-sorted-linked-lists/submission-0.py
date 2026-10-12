class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        res = []

        for node in lists:
            while node:
                inserted = False
                for i, num in enumerate(res):
                    if node.val <= num:
                        res.insert(i, node.val)
                        inserted = True
                        break
                if not inserted:
                    res.append(node.val)
                node = node.next

        dummy = ListNode()
        cur = dummy
        for val in res:
            cur.next = ListNode(val)
            cur = cur.next

        return dummy.next