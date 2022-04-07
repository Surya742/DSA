class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> zero_pos;

        // lake -> first zero
        unordered_map<int, int> m;

        bool zero_interval = false;

        for (int i = 0; i < rains.size(); ++i)
        {
            const auto rain = rains[i];
            if (!rain)
            {
                zero_pos.insert(i);
            }
            else
            {
                rains[i] = -1;

                auto res = m.emplace(rain, i);
                if (!res.second)
                {
                    auto zero_it = zero_pos.lower_bound(res.first->second);
                    if (zero_it == zero_pos.end()) return {};
                    rains[*zero_it] = rain;
                    zero_pos.erase(zero_it);
                    res.first->second = i + 1;
                }
            }
        }

        for (const auto i : zero_pos)
        {
            rains[i] = 1;
        }

        return std::move(rains);
    }
};