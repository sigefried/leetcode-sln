class ProductOfNumbers {
public:
    vector<int> store = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num != 0) {
            store.push_back(store.back() * num);
        } else {
            store = {1};
        }
    }
    
    int getProduct(int k) {
        return k < store.size() ? store.back() / store[store.size() - k - 1] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */