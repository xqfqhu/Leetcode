'''
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
'''
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> candidates;
        int n = wordList.size();
        vector<vector<string> > res;
        queue<vector<string> > paths;
        paths.push({beginWord});
        int level = 1;
        int wordL = beginWord.size();
        unordered_set<string> visited;
        
        for (int i = 0; i < n; i++){
            candidates.insert(wordList[i]);
        }
        candidates.erase(beginWord);
        while (!paths.empty()){
            vector<string> path = paths.front();
            paths.pop();
            
            if (level < path.size()){
                if (res.size() != 0) break;
                for (auto itr = visited.begin(); itr != visited.end(); itr++){
                    candidates.erase(*itr);
                }
                visited.clear();
                level++;
            }
            for(int i = 0; i < wordL; i++){
                string word = path.back();
                
                for (char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if (candidates.find(word) != candidates.end()){
                        path.push_back(word);
                        
                        if (word == endWord) res.push_back(path);
                        else{
                            paths.push(path);
                            
                        }
                        path.pop_back();
                        visited.insert(word);
                    }
                }
            }
        }
        return res;
    }
};

'''
this is a combination - find shortest combination problem. you should you BFS
there are two points here:
    1. how to check whether we have arrived at a new level?
        1. traverse a level in helper function, increment level in main function. see #45 for details
        2. if we have stored the path, we can check whether level < len(path) to see whether we have arrived at a new level
    2. to find the shortest path, all elems we have visited should be removed from candidates for all paths
        so you do not want a different candidates for each path
'''