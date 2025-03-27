class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>>mp=new HashMap<>();
        for(String s:strs){
            String x=s;
            char[] chars=s.toCharArray();
            Arrays.sort(chars);
            String key=new String(chars);
            if(!mp.containsKey(key)){
                mp.put(key,new ArrayList<>());
            }
            mp.get(key).add(s);
        }
        return new ArrayList<>(mp.values());
    }
}