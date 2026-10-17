from collections import defaultdict

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        components = 0
        graph = defaultdict(list)

        for source, destination in edges:
            graph[source].append(destination)
            graph[destination].append(source)

        visited = [False] * n


        for i in range(n):
            if not visited[i]:
                components += 1

                queue = deque([i])
                visited[i] = True

                while queue:
                    curr = queue.popleft()
                    for neighbor in graph[curr]:
                        if not visited[neighbor]:
                            visited[neighbor] = True
                            queue.append(neighbor)
                



        return components