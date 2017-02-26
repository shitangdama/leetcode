<<<<<<< HEAD
public class MeetingRooms {
    
    public boolean canAttendMeetings(Interval[] intervals) {
        assert intervals != null : "null input";
        
        Arrays.sort(intervals, (o1, o2) -> {
            int r = o1.start - o2.start;
            return r == 0 ? o1.end - o2.end : r;
        });
        
        for (int i = 1; i < intervals.length; i++) {
            Interval i1 = intervals[i - 1];
            Interval i2 = intervals[i];
            if (i1.end > i2.start) {
                return false;
            }
        }
        
        return true;
    }
=======
public class MeetingRooms {
    
    public boolean canAttendMeetings(Interval[] intervals) {
        assert intervals != null : "null input";
        
        Arrays.sort(intervals, (o1, o2) -> {
            int r = o1.start - o2.start;
            return r == 0 ? o1.end - o2.end : r;
        });
        
        for (int i = 1; i < intervals.length; i++) {
            Interval i1 = intervals[i - 1];
            Interval i2 = intervals[i];
            if (i1.end > i2.start) {
                return false;
            }
        }
        
        return true;
    }
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}