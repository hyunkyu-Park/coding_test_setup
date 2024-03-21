#include <iostream>
#include <map>
#include <map>
template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// update the values in the m_map.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
// INSERT YOUR SOLUTION HERE
///////////////////////////////////////////////////////
		// Check if the interval is empty
        if (!(keyBegin < keyEnd)) {
            return; // Do nothing for an empty interval
        }

        auto begin_lower = m_map.lower_bound(keyBegin);
        auto end_lower = m_map.lower_bound(keyEnd);
        auto end_upper = m_map.upper_bound(keyEnd);
        bool exist_index = false;

        auto it = m_map.find(keyEnd);
        // if there is an index of keyEnd
        if (it != m_map.end()) {
            if (it->second == val) {
                m_map.erase(it);
            }
            else{
                exist_index=true;
            }
        }
        else {
            if (end_lower != m_map.begin()) {
                --end_lower;
                if (end_lower->second != val) {
                    if (end_upper != m_map.end()) {
                        V temp_val = end_lower->second;
                        m_map.erase(end_lower->first);
                        m_map[keyEnd] = temp_val;
                    }
                }
            } 
        }

        begin_lower = m_map.lower_bound(keyBegin);
        end_upper = m_map.lower_bound(keyEnd);
        if(exist_index){
            m_map.erase(begin_lower, end_lower);
        }
        else{
            m_map.erase(begin_lower, end_upper);
        }

        begin_lower = m_map.lower_bound(keyBegin);

        if (begin_lower != m_map.begin()) {
			--begin_lower;
			K begin_prev_key = begin_lower->first;
			V value = m_map[begin_prev_key];
			if (value != val) {
				m_map[keyBegin] = val;
			}
        } else {
            // case 1
            m_map[keyBegin] = val;
        }  
    }

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.

// 테스트 함수
void IntervalMapTest() {
    // interval_map 생성자 호출
    interval_map<int, char> M('A');

    // 여러 구간에 대한 assign 수행
    M.assign(0, 3, 'B');
    M.assign(3, 6, 'C');
    M.assign(6, 7, 'A');
    M.assign(7, 9, 'P');

    // M.assign(-1, 4, 'Z');
    // M.assign(-1, 0, 'Z');
    // M.assign(-2, 0, 'Z');
    // M.assign(-2, 1, 'Z');
    // M.assign(1, 4, 'B');
    // M.assign(1, 4, 'K');
    // M.assign(1, 4, 'C');
    M.assign(8, 16, 'M');
    // M.assign(4, 1, 'M');
}

int main() {
    // 테스트 함수 호출
    IntervalMapTest();

    return 0;
}
