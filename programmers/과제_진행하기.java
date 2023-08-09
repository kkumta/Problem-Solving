import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        String[] ans = new String[plans.length];
        int ansIdx = 0;

        // 시작 시간이 빠른 순으로 과제 정렬하기
        List<Plan> planList = new ArrayList<>();
        for (String[] plan : plans) {
            int time = (plan[1].charAt(0) - '0') * 10 * 60;
            time += (plan[1].charAt(1) - '0') * 60;
            time += (plan[1].charAt(3) - '0') * 10;
            time += plan[1].charAt(4) - '0';
            planList.add(new Plan(plan[0], time, Integer.parseInt(plan[2])));
        }
        Collections.sort(planList);

        // 과제 진행하기
        // 과제를 진행하는 중에 새로운 과제를 시작할 시간이 되면 기존에 진행하던 과제는 스택에 넣기
        Stack<Plan> stack = new Stack<>();
        for (int i = 0; i < planList.size() - 1; i++) {
            int curTime = planList.get(i).start;
            if (curTime + planList.get(i).playtime < planList.get(i + 1).start) { // 현재 과제를 끝내고 다음 과제를 시작할 때까지 시간이 남는 경우
                curTime += planList.get(i).playtime;
                ans[ansIdx++] = planList.get(i).name;
                while (!stack.isEmpty()) {
                    if (curTime + stack.peek().playtime <= planList.get(i + 1).start) { // 과제 1개를 끝낼 수 있을 경우
                        curTime += stack.peek().playtime;
                        ans[ansIdx++] = stack.pop().name;
                    } else if (curTime < planList.get(i + 1).start) { // 과제 1개 중 일부를 끝낼 수 있을 경우
                        Plan plan = stack.pop();
                        plan.playtime -= planList.get(i + 1).start - curTime;
                        stack.push(plan);
                        break;
                    } else { // 과제를 할 수 없을 경우
                        break;
                    }
                }
            } else if (curTime + planList.get(i).playtime == planList.get(i + 1).start) { // 현재 과제를 끝내는 시간과 다음 과제를 시작하는 시간이 같을 경우
                curTime += planList.get(i).playtime;
                ans[ansIdx++] = planList.get(i).name;
            } else { // 현재 과제를 다 끝내지 못하고 다음 과제를 하는 경우
                planList.get(i).playtime -= planList.get(i + 1).start - curTime;
                stack.push(planList.get(i));
            }
        }

        // 마지막 과제 + 스택에 남은 과제 진행
        ans[ansIdx++] = planList.get(planList.size() - 1).name;
        while (!stack.isEmpty()) {
            ans[ansIdx++] = stack.pop().name;
        }

        return ans;
    }

    private class Plan implements Comparable<Plan> {
        String name;
        int start;
        int playtime;

        public Plan(String name, int start, int playtime) {
            this.name = name;
            this.start = start;
            this.playtime = playtime;
        }

        @Override
        public int compareTo(Plan o) {
            return this.start - o.start;
        }
    }
}