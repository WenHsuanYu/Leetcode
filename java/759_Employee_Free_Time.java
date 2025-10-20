// Merging Interval
// TC: O(nlogn), where n is # intervals
// SC: O(n)

import java.util.ArrayList;
import java.util.List;

public int[][] employeeFreeTime(int[][][] schedule) {
    List<int[]> intervals = new ArrayList<>();
    for (int[][] employee : schedule) {
        for (int[] interval : employee) {
            intervals.add(interval);
        }
    }
    
    intervals.sort((a, b) -> a[0] - b[0]);
    
    List<int[]> merged = new ArrayList<>();
    for (int[] interval : intervals) {
        if (merged.isEmpty() || merged.get(merged.size() - 1)[1] < interval[0]) {
            merged.add(interval);
        } else {
            merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], interval[1]);
        }
    }
    
    List<int[]> result = new ArrayList<>();
    for (int i = 1; i < merged.size(); i++) {
        result.add(new int[]{merged.get(i - 1)[1], merged.get(i)[0]});
    }
    
    return result.toArray(new int[result.size()][]);
}

//Sweep-line 掃描線
//TC: O(nlogn)
//SC: O(n)
public int[][] employeeFreeTime(int[][][] schedule) {
    List<int[]> events = new ArrayList<>();
    for (int[][] employee : schedule) {
        for (int[] interval : employee) {
            events.add(new int[]{interval[0], 1});
            events.add(new int[]{interval[1], -1});
        }
    }
    
    events.sort((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
    
    List<int[]> result = new ArrayList<>();
    int count = 0, start = -1;
    
    for (int[] event : events) {
        if (count == 0 && start != -1) {
            result.add(new int[]{start, event[0]});
        }
        count += event[1];
        if (count == 0) {
            start = event[0];
        }
    }
    
    return result.toArray(new int[result.size()][]);
}

// Direct Compare
//TC: O(nlogn)
//SC: O(n)
public int[][] employeeFreeTime(int[][][] schedule) {
    List<int[]> intervals = new ArrayList<>();
    for (int[][] employee : schedule) {
        for (int[] interval : employee) {
            intervals.add(interval);
        }
    }
    
    intervals.sort((a, b) -> a[0] - b[0]);
    
    List<int[]> result = new ArrayList<>();
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals.get(i)[0] > intervals.get(i-1)[1]) {
            result.add(new int[]{intervals.get(i-1)[1], intervals.get(i)[0]});
        }
    }
    
    return result.toArray(new int[result.size()][]);
}
