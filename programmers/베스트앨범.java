import java.util.*;
import java.util.Map.Entry;

class Solution {
    
    class Info {
        
        int number;
        String genre;
        int plays;
        
        public Info(int number, String genre, int plays) {
            this.number = number;
            this.genre = genre;
            this.plays = plays;
        }
    }
    
    HashMap<String, Integer> genresPlays = new HashMap<>(); // key: 장르, value: 장르별 재생횟수
    
    public int[] solution(String[] genres, int[] plays) {
        
        for (int i = 0; i < genres.length; i++) {
            genresPlays.put(genres[i], genresPlays.getOrDefault(genres[i], 0) + plays[i]);
        }
        
        List<Map.Entry<String, Integer>> genresSort = new ArrayList<>(genresPlays.entrySet());
        genresSort.sort(new Comparator<Entry<String, Integer>>() {
            @Override
            public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
                return o2.getValue() - o1.getValue();
            }
        });
        
        List<Info>[] songsOfGenres = new ArrayList[genresSort.size()];
        for (int i = 0; i < genresSort.size(); i++) {
            songsOfGenres[i] = new ArrayList<>();
        }
        for (int i = 0; i < genres.length; i++) {
            for (int j = 0; j < songsOfGenres.length; j++) {
                if (genresSort.get(j).getKey().equals(genres[i])) {
                    songsOfGenres[j].add(new Info(i, genres[i], plays[i]));
                    break;
                }
            }
        }
        
        for (int i = 0; i < songsOfGenres.length; i++) {
            songsOfGenres[i].sort(new Comparator<Info>() {
                @Override
                public int compare(Info o1, Info o2) {
                    if (o1.plays == o2.plays) {
                        return o1.number - o2.number;
                    }
                    return o2.plays - o1.plays;
                }
            });
        }
        
        ArrayList<Integer> answerList = new ArrayList<>();
        
        for (int i = 0; i < songsOfGenres.length; i++) {
            if (songsOfGenres[i].size() > 1) {
                for (int j = 0; j < 2; j++) {
                    answerList.add(songsOfGenres[i].get(j).number);
                }
            } else {
                answerList.add(songsOfGenres[i].get(0).number);
            }
        }
        
        int[] answer = new int[answerList.size()];
        for (int i = 0; i < answerList.size(); i++) {
            answer[i] = answerList.get(i);
        }
        
        return answer;
    }
}
