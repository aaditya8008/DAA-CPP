#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <type_traits>

using namespace std;

template <typename k, typename v>
class HashMap {
private:
    struct Node {
        k key;
        v value;

        Node(k key, v value) : key(key), value(value) {}
    };

    int n;                           // Number of elements
    int N;                           // Number of buckets
    vector<list<Node>> buckets;      // Array of linked lists as buckets

    int hashFunction(k key) {
        int hc = hash<k>{}(key);
        return abs(hc) % buckets.size();
    }

    int searchInLL(k key, int bi) {
        list<Node>& ll = buckets[bi];
        int di = 0;
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            if (it->key == key) {
                return di;
            }
            di++;
        }
        return -1;
    }

    void rehash() {
        vector<list<Node>> oldBuckets = buckets;
        buckets.resize(N * 2);
        N = 2 * N;

        for (auto& bucket : buckets) {
            bucket.clear();
        }

        for (auto& oldBucket : oldBuckets) {
            for (auto it = oldBucket.begin(); it != oldBucket.end();) {
                Node node = *it;
                it = oldBucket.erase(it);
                put(node.key, node.value);
            }
        }
    }

public:
    HashMap() : n(0), N(4) {
        buckets.resize(4);
    }

    void put(k key, v value) {
        clock_t startTime = clock();

        int bi = hashFunction(key);
        int di = searchInLL(key, bi);
        if (di != -1) {
            auto it = buckets[bi].begin();
            advance(it, di);
            it->value = value;
        } else {
            buckets[bi].emplace_back(key, value);
            n++;
        }

        double lambda = (double)n / N;
        if (lambda > 2.0) {
            rehash();
        }

        clock_t endTime = clock();
        cout << "Put operation took: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    }

    v get(k key) {
        clock_t startTime = clock();

        int bi = hashFunction(key);
        int di = searchInLL(key, bi);
        if (di != -1) {
            auto it = buckets[bi].begin();
            advance(it, di);
            v value = it->value;

            clock_t endTime = clock();
            cout << "Get operation took: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
            return value;
        } else {
            clock_t endTime = clock();
            cout << "Get operation took: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
            return v();
        }
    }

    void remove(k key) {
        clock_t startTime = clock();

        int bi = hashFunction(key);
        int di = searchInLL(key, bi);
        if (di != -1) {
            auto it = buckets[bi].begin();
            advance(it, di);
            buckets[bi].erase(it);
            n--;
        }

        clock_t endTime = clock();
        cout << "Remove operation took: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    }

    bool containsKey(k key) {
        clock_t startTime = clock();

        int bi = hashFunction(key);
        int di = searchInLL(key, bi);
        bool result = (di != -1);

        clock_t endTime = clock();
        cout << "ContainsKey operation took: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
        return result;
    }

    vector<k> keySet() {
        vector<k> keys;
        for (auto& bucket : buckets) {
            for (auto& node : bucket) {
                keys.push_back(node.key);
            }
        }
        return keys;
    }

    bool isEmpty() {
        return n == 0;
    }

   void generator() {
    srand(time(0));
    int flag = 1;
    string keyInput;
    string valueInput;
    while (flag == 1) {
        k key;
        v value;

        cout << "Enter key: ";
        cin >> keyInput;
        cout << "Enter value: ";
        cin >> valueInput;

        key = keyInput;
       

        put(key, value);
        cout << "Want to Continue(1/0): ";
        try {
            cin >> flag;
        } catch (exception e) {
            cout << "Invalid input. Exiting." << endl;
            flag = 0;
        }
    }
}


    void display() {
        cout << "HashMap Contents:" << endl;
        for (size_t i = 0; i < buckets.size(); i++) {
            cout << "Bucket " << i << ": ";
            for (auto& node : buckets[i]) {
                cout << "(" << node.key << ", " << node.value << ") ";
            }
            cout << endl;
        }
    }

    int size() {
        return n;
    }

    void clear() {
        for (auto& bucket : buckets) {
            bucket.clear();
        }
        n = 0;
    }

    double loadFactor() {
        return (double)n / N;
    }

    // Add more utility methods as needed...
};

int main() {
    HashMap<string, int> hm;
    hm.generator();

    hm.display();
    cout << "HashMap size: " << hm.size() << endl;
    cout << "Load Factor: " << hm.loadFactor() << endl;

    vector<string> keys = hm.keySet();
    cout << "Keys, Values:" << endl;
    for (auto& key : keys) {
        cout << key << " : " << hm.get(key) << endl;
    }

    return 0;
}










