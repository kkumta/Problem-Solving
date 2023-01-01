import java.util.*;

class Solution {
    
    public int solution(int[][] jobs) {
        Queue<Job> inTimeQueue = new PriorityQueue<>(jobs.length, new Comparator<Job>() {
            @Override
            public int compare(Job o1, Job o2) {
                return o1.inTime - o2.inTime;
            }
        });
        Queue<Job> workingTimeQueue = new PriorityQueue<>(jobs.length, new Comparator<Job>() {
            @Override
            public int compare(Job o1, Job o2) {
                return o1.workingTime - o2.workingTime;
            }
        });
        
        for (int[] job : jobs) {
            inTimeQueue.add(new Job(job[0], job[1]));
        }
        
        int curTime = 0;
        int sumTime = 0;
        while (!inTimeQueue.isEmpty() || !workingTimeQueue.isEmpty()) {
            while (!inTimeQueue.isEmpty() && inTimeQueue.peek().inTime <= curTime) {
                workingTimeQueue.add(inTimeQueue.poll());
                
            }
            while (workingTimeQueue.isEmpty()) {
                curTime = inTimeQueue.peek().inTime;
                while (inTimeQueue.peek().inTime == curTime) {
                    workingTimeQueue.add(inTimeQueue.poll());
                }
            }
            curTime += workingTimeQueue.peek().workingTime;
            sumTime += curTime - workingTimeQueue.poll().inTime;
        }
        
        return sumTime / jobs.length;
    }
    
    private class Job {
        
        int inTime;
        int workingTime;
        
        public Job(int inTime, int workingTime) {
            this.inTime = inTime;
            this.workingTime = workingTime;
        }
    }
}