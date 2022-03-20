import java.util.*;

class Solution {

    private class Vertex {

        String word;
        int count = 0;

        public Vertex(String word) {
            this.word = word;
        }
    }

    boolean[] visited;

    public int solution(String begin, String target, String[] words) {

        int answer = 0;
        visited = new boolean[words.length + 1];

        Vertex[] vertices = new Vertex[words.length + 1];
        vertices[0] = new Vertex(begin);

        for (int i = 0; i < words.length; i++) {
            vertices[i + 1] = new Vertex(words[i]);
        }

        answer = bfs(vertices, target);
        if (answer == 51) {
            answer = 0;
        }

        return answer;
    }

    private int bfs(Vertex[] vertices, String target) {

        int shortest = 51;

        Queue<Vertex> queue = new LinkedList<>();
        queue.add(vertices[0]);
        visited[0] = true;

        while (!queue.isEmpty()) {
            Vertex x = queue.poll();
            for (int i = 1; i < vertices.length; i++) {
                if (!visited[i]) {
                    int sameCount = 0;
                    for (int j = 0; j < vertices[0].word.length(); j++) {
                        if (x.word.charAt(j) == vertices[i].word.charAt(j)) {
                            ++sameCount;
                        }
                    }
                    if (sameCount == x.word.length() - 1) { // 유효한 방문일 때(각 단계에 맞는 방문)
                        visited[i] = true;
                        vertices[i].count = x.count + 1;
                        queue.add(vertices[i]);

                        if (target.equals(vertices[i].word) && (shortest > vertices[i].count)) {
                            shortest = vertices[i].count;
                        }
                    }
                }
            }
        }
        return shortest;
    }
}
