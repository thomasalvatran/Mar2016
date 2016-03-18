#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class DistanceToCity
{
    string name;
    int distance;
public:
    DistanceToCity(){}
    DistanceToCity(string n, int d): name(n), distance(d){}
    bool operator < (const DistanceToCity right) const { return right.distance < distance; }
    string getName() const { return name; }
    void setName(const string &value) { name = value;}
    int getDistance() const { return distance;}
    void setDistance(int value) { distance = value;}
};

class DistanceFinder
{
public:
    multimap<string, DistanceToCity> cities;
    multimap<string, DistanceToCity> :: iterator Citr, stop, p;
    void setDistance(string from, string to, int distance)
    {
        cities.insert(make_pair(from, DistanceToCity(to, distance)));
    }
    priority_queue<DistanceToCity> findDistance(string start, map<string, int> &shortest)
    {
        priority_queue<DistanceToCity> que, que1;
        que.push(DistanceToCity(start, 0));
        while(!que.empty())
        {
            DistanceToCity new_city = que.top();
            que.pop();
            if (shortest.count(new_city.getName()) == 0) //not visited
            {
                int d = new_city.getDistance();
                shortest[new_city.getName()] = d; //visited ??
                que1.push(DistanceToCity(new_city.getName(), d));
                p = cities.lower_bound(new_city.getName());
                stop = cities.upper_bound(new_city.getName());
                while (p != stop)
                {
                    DistanceToCity next_destination = p->second;
                    int total_distance = d + next_destination.getDistance();
                    que.push(DistanceToCity(next_destination.getName(), total_distance));
                    p++;
                }
            }
        }
        return que1;
    }
};
void print(DistanceFinder d)
{
multimap<string, DistanceToCity>::iterator i;
for (i = d.cities.begin(); i != d.cities.end(); ++i)
    cout << i->first << " " << i->second.getName() << " " << i->second.getDistance() << endl;
//Lambda multimap iterator
for_each(d.cities.begin(), d.cities.end(),[](pair<string, DistanceToCity> i){
    cout << i.first <<" "<< i.second.getName() << " " << i.second.getDistance() << endl;
});
}
//std::for_each(begin(v), end(v), [&sum](int x) { sum += x; });

int main()
{
    DistanceFinder d;
    d.setDistance("Pendleton", "Phoenix", 4);
    d.setDistance("Pendleton", "Pueblo", 8);
    d.setDistance("Pensacola", "Phoenix", 5);
    d.setDistance("Peoria", "Pittsburgh", 5);
    d.setDistance("Peoria", "Pueblo", 3);
    d.setDistance("Phoenix", "Peoria", 4);
    d.setDistance("Phoenix", "Pittsburgh", 10);
    d.setDistance("Phoenix", "Pueblo", 3);
    d.setDistance("Pierre", "Pendleton", 2);
    d.setDistance("Pittsburgh", "Pensacola", 4);
    d.setDistance("Princeton", "Pittsburgh", 2);
    d.setDistance("Pueblo", "Pierre", 3);
    print(d);

    map<string, int> shortest;
    priority_queue<DistanceToCity> pq = d.findDistance("Pierre", shortest);
    while(!pq.empty())
    {
        DistanceToCity p = pq.top();
        pq.pop();
        cout << p.getName() << " " << p.getDistance() << endl;
    }
    return 0;
}

