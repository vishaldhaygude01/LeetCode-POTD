class SmallestInfiniteSet
{
public:
    set<int> tmp;
    SmallestInfiniteSet()
    {
        tmp.clear();

        int i = 1;
        while (i <= 1000)
        {
            tmp.insert(i);
            i++;
        }
    }

    int popSmallest()
    {
        int curr = *tmp.begin();
        tmp.erase(tmp.begin());
        return curr;
    }

    void addBack(int num)
    {
        tmp.insert(num);
    }
};
