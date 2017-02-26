public boolean wordPattern(String pattern, String str) {
    if (pattern == null || str == null) {
        return false;
    }
    char[] patterns = pattern.toCharArray();
    String[] strs = str.split(" ");
    if (patterns.length != strs.length) {
        return false;
    }
    Map<Character, String> map = new HashMap<Character, String>();
    for (int i=0; i<patterns.length; i++) {
        if (map.containsKey(patterns[i])) {
            if (!map.get(patterns[i]).equals(strs[i])) {
                return false;
            }
        } else if (map.containsValue(strs[i])) {
            return false;
        }
        map.put(patterns[i], strs[i]);
    }
    return true;
}