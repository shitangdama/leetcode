<<<<<<< HEAD
package CompareVersionNumbers;

public class CompareVersionNumbers {
    public int compareVersion(String version1, String version2) {
        String[] subversions1 = version1.split("\\.");
        String[] subversions2 = version2.split("\\.");
        int len = Math.max(subversions1.length, subversions2.length);
        for (int i = 0; i < len; i++) {
            int subversion1 = i < subversions1.length ? Integer.parseInt(subversions1[i]) : 0;
            int subversion2 = i < subversions2.length ? Integer.parseInt(subversions2[i]) : 0;
            if (subversion1 > subversion2) return 1;
            else if (subversion1 < subversion2) return -1;
        }
        return 0;
    }
}


public class CompareVersionNumbers {
	public int compareVersion(String version1, String version2) {
	    String[] levels1 = version1.split("\\.");
	    String[] levels2 = version2.split("\\.");

	    int length = Math.max(levels1.length, levels2.length);
	    for (int i=0; i<length; i++) {
	        Integer v1 = i < levels1.length ? Integer.parseInt(levels1[i]) : 0;
	        Integer v2 = i < levels2.length ? Integer.parseInt(levels2[i]) : 0;
	        int compare = v1.compareTo(v2);
	        if (compare != 0) {
	            return compare;
	        }
	    }

	    return 0;
	}
	
	public static void main(String args[]) {
		CompareVersionNumbers solution = new CompareVersionNumbers();
		System.out.println(solution.compareVersion("1.2.43", "1.2.4"));
	}
=======
package CompareVersionNumbers;

public class CompareVersionNumbers {
    public int compareVersion(String version1, String version2) {
        String[] subversions1 = version1.split("\\.");
        String[] subversions2 = version2.split("\\.");
        int len = Math.max(subversions1.length, subversions2.length);
        for (int i = 0; i < len; i++) {
            int subversion1 = i < subversions1.length ? Integer.parseInt(subversions1[i]) : 0;
            int subversion2 = i < subversions2.length ? Integer.parseInt(subversions2[i]) : 0;
            if (subversion1 > subversion2) return 1;
            else if (subversion1 < subversion2) return -1;
        }
        return 0;
    }
}


public class CompareVersionNumbers {
	public int compareVersion(String version1, String version2) {
	    String[] levels1 = version1.split("\\.");
	    String[] levels2 = version2.split("\\.");

	    int length = Math.max(levels1.length, levels2.length);
	    for (int i=0; i<length; i++) {
	        Integer v1 = i < levels1.length ? Integer.parseInt(levels1[i]) : 0;
	        Integer v2 = i < levels2.length ? Integer.parseInt(levels2[i]) : 0;
	        int compare = v1.compareTo(v2);
	        if (compare != 0) {
	            return compare;
	        }
	    }

	    return 0;
	}
	
	public static void main(String args[]) {
		CompareVersionNumbers solution = new CompareVersionNumbers();
		System.out.println(solution.compareVersion("1.2.43", "1.2.4"));
	}
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
}