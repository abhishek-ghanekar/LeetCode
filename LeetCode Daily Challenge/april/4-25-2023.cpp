class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++) s.insert(i);
    }
    
    int popSmallest() {
        int a = *s.begin();
        s.erase(a);
        return a;

        
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};
