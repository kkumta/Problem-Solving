import java.util.*;

class Solution {

    private class CarRecord implements Comparable<CarRecord> {

        String number;
        Stack<Integer> stack = new Stack();
        int time = 0;
        int fee = 0;

        public CarRecord(String number) {
            this.number = number;
        }

        @Override
        public int compareTo(CarRecord o) {
            return Integer.parseInt(number) - Integer.parseInt(o.number);
        }
    }

    public int[] solution(int[] fees, String[] records) {

        int toMinute2359 = 23 * 60 + 59;

        // 1. 입출차 정보를 각 차별로 구분하여 담을 ArrayList 생성
        ArrayList<CarRecord> carRecordList = new ArrayList<CarRecord>();

        // 2. 입출차 정보를 통해 각 차량별 누적 주차 시간 구하기
        for (int i = 0; i < records.length; i++) {
            StringTokenizer st = new StringTokenizer(records[i]);

            String timeStr = st.nextToken();
            int time = (timeStr.charAt(0) - '0') * 10;
            time += (timeStr.charAt(1) - '0');
            time *= 60;
            time += (timeStr.charAt(3) - '0') * 10;
            time += (timeStr.charAt(4) - '0');

            String number = st.nextToken();
            String situation = st.nextToken();

            boolean recordFlag = false;
            for (int j = 0; j < carRecordList.size(); j++) {
                if (carRecordList.get(j).number.equals(number)) { // 만약 이미 기록이 있는 차 번호라면
                    recordFlag = true;
                    if (situation.equals("IN")) { // 만약 입차되는 차라면 Stack에 PUSH 해준다.
                        carRecordList.get(j).stack.push(time);
                    } else {
                        int inTime = carRecordList.get(
                            j).stack.pop(); // 만약 출차되는 차라면 Stack에서 POP 해준다.
                        carRecordList.get(
                            j).time += (time - inTime);
                    }
                    break;
                }
            }
            if (!recordFlag) { // 만약 아직 기록이 없는 차 번호라면
                carRecordList.add(new CarRecord(number));
                carRecordList.get(carRecordList.size() - 1).stack.push(
                    time); // 입차된 적 없는 차는 출차될 수 없기 때문에 무조건 입차시킨다.
            }
        }

        for (int i = 0; i < carRecordList.size(); i++) {
            if (!carRecordList.get(
                i).stack.isEmpty()) { // 만약 입차된 기록만 있고 출차된 기록은 없는 차량이 존재한다면(==스택에 값이 존재한다면)
                carRecordList.get(i).time += toMinute2359 - carRecordList.get(i).stack.pop();
            }
        }

        // 3. 각 차량별 누적 주차 시간을 통해 각 차량별 주차요금 구하기
        for (int i = 0; i < carRecordList.size(); i++) {
            carRecordList.get(i).fee = fees[1]; // 기본 요금

            int overTime = carRecordList.get(i).time - fees[0]; // 초과 시간
            if (overTime > 0) {// 초과 요금 계산
                carRecordList.get(i).fee += (overTime / fees[2]) * fees[3];
                if (overTime % fees[2] != 0) { // 초과한 시간이 단위 시간으로 나누어 떨어지지 않는다면 올림
                    carRecordList.get(i).fee += fees[3];
                }
            }
        }

        // 4. 차량 번호가 작은 자동차순으로 정렬하기
        CarRecord[] array = carRecordList.toArray(new CarRecord[carRecordList.size()]);
        Arrays.sort(array);

        // 5. 주차 요금을 정수 배열에 담기
        int[] answer = new int[carRecordList.size()];
        for (int i = 0; i < carRecordList.size(); i++) {
            answer[i] = array[i].fee;
        }

        return answer;
    }
}
