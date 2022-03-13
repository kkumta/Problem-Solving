import java.util.*;

class Solution {
    private class User {

        String id;
        int mail = 0;
        ArrayList<String> reportUsers = new ArrayList<>();

        public User(String id) {
            this.id = id;
        }
    }

    public int[] solution(String[] id_list, String[] report, int k) {

        int[] answer = new int[id_list.length];

        // 1. 유저 배열 만들기
        User[] users = new User[id_list.length];
        for (int i = 0; i < id_list.length; i++) {
            users[i] = new User(id_list[i]);
        }

        // 2. 신고당한 유저 객체에 신고한 유저의 아이디 추가하기
        for (int i = 0; i < report.length; i++) {
            StringTokenizer st = new StringTokenizer(report[i]);
            String userId = st.nextToken();
            String reportedId = st.nextToken();
            addReportUser(users, userId, reportedId);
        }

        // 3. k번 이상 신고당한 유저를 찾아 각 유저별 메일을 받은 횟수 계산하기
        for (int i = 0; i < id_list.length; i++) {
            if (users[i].reportUsers.size() >= k) { // 만약 k번 이상 신고당한 유저라면
                for (int j = 0; j < users[i].reportUsers.size(); j++) { // 그 유저를 신고한 유저들을 찾아 mail 횟수를 1씩 증가시킨다
                    addMailCount(users, users[i].reportUsers.get(j));
                }
            }
        }

        // 4. 각 유저별 메일을 받은 횟수를 배열로 만들기
        for (int i = 0; i < id_list.length; i++) {
            answer[i] = users[i].mail;
        }

        return answer;
    }

    private void addReportUser(User[] users, String userId, String reportedId) {

        for (int i = 0; i < users.length; i++) {
            if (users[i].id.equals(reportedId)) { // 신고당한 유저 찾기
                if (!users[i].reportUsers.contains(userId)) { // 아직 같은 사람을 신고한 적이 없다면,
                    users[i].reportUsers.add(userId); // 신고한 사람 목록에 넣기
                }
            }
        }
    }

    private void addMailCount(User[] users, String userId) {

        for (int i = 0; i < users.length; i++) {
            if (users[i].id.equals(userId)) { // 신고한 유저 찾기
                ++users[i].mail; // 메일 횟수 증가시키기
            }
        }
    }
}
