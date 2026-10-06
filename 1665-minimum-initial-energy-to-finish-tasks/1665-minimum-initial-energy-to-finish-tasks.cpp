
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int initialEnergy = 0;
        int currentEnergy = 0;

        for (auto& task : tasks) {
            int actualEnergy = task[0];
            int minimumEnergy = task[1];

            if (currentEnergy < minimumEnergy) {
                initialEnergy += minimumEnergy - currentEnergy;
                currentEnergy = minimumEnergy;
            }

            currentEnergy -= actualEnergy;
        }

        return initialEnergy;
    }
};


