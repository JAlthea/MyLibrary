#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wordBackTracking(vector<string> &words, int index) {
    if (words.front() == words.back())  //if words.size = 1
        return index;
    
    vector<string> filteredWords;
    int plus = 0;   //for next index
    int sum = 0;    //for return
    char nextStart = words[0][index];
    for (int i=0; i<words.size(); i++)
    {
        if (!words[i][index])   //In case : words = { "wod", "wode" }, index = 3, words[i] = "wod", words[i][index] = '\0'
        {
            sum += index;
            continue;
        }
        
        if (nextStart == words[i][index])
        {
            if (!words[i][index + 1])   //In case : words = { "wo", "wod" }, index = 1, words[i] = "wo", words[i][index] = 'o'
            {
                sum += index + 1;
                plus = 1;
            }
            else
                filteredWords.push_back(words[i]);
        }
        else
        {
            nextStart = words[i][index];
            if (!filteredWords.empty())
                sum += wordBackTracking(filteredWords, index + 1 + plus);
            
            filteredWords = vector<string>();   //clear
            plus = 0;
            i--;
        }
    }
    
    if (!filteredWords.empty())
        sum += wordBackTracking(filteredWords, index + 1 + plus);
    
    return sum;
}

int getMinWordCount(vector<string> words) {
    sort(words.begin(), words.end());  //original list : [word, war, warrior, world], sorted list : [war, warrior, word, world]
    return wordBackTracking(words, 0);
}
