#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        map<int, int> elementToColor;
        map<int, int> colorCount;
        set<int> uniqueColors;
        vector<int> ans;

        for (const auto &query : queries)
        {
            int element = query[0];
            int color = query[1];

            if (elementToColor.find(element) != elementToColor.end())
            {
                int prevColor = elementToColor[element];
                colorCount[prevColor]--;
                if (colorCount[prevColor] == 0)
                {
                    uniqueColors.erase(prevColor);
                }
            }

            elementToColor[element] = color;
            colorCount[color]++;
            uniqueColors.insert(color);

            ans.push_back(uniqueColors.size());
        }

        return ans;
    }
};
