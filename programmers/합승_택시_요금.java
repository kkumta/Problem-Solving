import java.util.*;

class Solution {

    long MAX = 400000000L;

    public int solution(int n, int s, int a, int b, int[][] fares) {
        long[] sCostSum = findDistance(n, s, fares);
        long[] aCostSum = findDistance(n, a, fares);
        long[] bCostSum = findDistance(n, b, fares);

        long ans = MAX;
        for (int i = 1; i <= n; i++) {
            if (sCostSum[i] + aCostSum[i] + bCostSum[i] < ans) {
                ans = sCostSum[i] + aCostSum[i] + bCostSum[i];
            }
        }

        return (int) ans;
    }

    private long[] findDistance(int n, int start, int[][] fares) {
        long[] distance = new long[n + 1];
        Arrays.fill(distance, MAX);
        distance[start] = 0;

        // 인접 리스트 만들기
        List<Pair>[] adjList = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int i = 0; i < fares.length; i++) {
            adjList[fares[i][0]].add(new Pair(fares[i][1], fares[i][2]));
            adjList[fares[i][1]].add(new Pair(fares[i][0], fares[i][2]));
        }

        // 다익스트라 알고리즘으로 start에서 다른 모든 정점으로 가는 최단 경로 찾기
        Queue<Pair> queue = new PriorityQueue<>();
        queue.add(new Pair(start, distance[start]));
        while (!queue.isEmpty()) {
            Pair cur = queue.poll();
            if (distance[cur.des]
                    < cur.cost) { // 현재 cur의 비용이 최소비용 배열에 있는 cur 비용보다 크다면 이 정점은 더이상 탐색할 가치가 없다
                continue;
            }

            for (Pair next : adjList[cur.des]) {
                if (distance[next.des] > distance[cur.des] + next.cost) {
                    distance[next.des] = distance[cur.des] + next.cost;
                    queue.add(new Pair(next.des, distance[next.des]));
                }
            }
        }

        return distance;
    }

    private class Pair implements Comparable<Pair> {
        int des;
        long cost;

        public Pair(int des, long cost) {
            this.des = des;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair o) {
            return (int) (this.cost - o.cost);
        }
    }
}