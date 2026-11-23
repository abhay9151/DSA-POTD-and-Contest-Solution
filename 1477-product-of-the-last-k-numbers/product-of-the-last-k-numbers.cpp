class ProductOfNumbers {
public:
	vector<int> temp;

	ProductOfNumbers() {
		temp = {1};
	}

	void add(int num) {
		if(num == 0){
			temp = {1};
		}
		else{
			temp.push_back(temp.back() * num);
		}
	}

	int getProduct(int k) {
		if(k >= temp.size()) return 0;

		return temp.back() / temp[temp.size() - k - 1];
	}
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */