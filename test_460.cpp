//
// Created by zhaobo on 2022/3/14.
//
/*
 * 请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。

函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lfu-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/*
 * 示例：

输入：
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
输出：
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

解释：
// cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // 返回 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // 返回 -1（未找到）
lfu.get(3);      // 返回 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // 返回 -1（未找到）
lfu.get(3);      // 返回 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // 返回 4
                 // cache=[3,4], cnt(4)=2, cnt(3)=3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lfu-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <map>
#include <list>
//#include <iostream>

using namespace std;

class LFUCache {
    // 缓存容量
    int _capacity;

    // 键值表
    map<int, int> _keyToVal;

    // 键和出现频率表
    map<int, int> _keyToFreq;

    // 频率和键-链表
    map<int, list<int>> _freqToKeys;

    // 当前最小频率
    int _minFreq;
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        _minFreq = 0;
    }

    int get(int key) {
        if (!_keyToVal.count(key) || _capacity <= 0) {
            return -1;
        }
        incrFreq(key);
        return _keyToVal[key];
    }

    void put(int key, int value) {
        if (_capacity <= 0) {
            return;
        }
        if (_keyToVal.count(key)) {
            _keyToVal[key] = value;
            incrFreq(key);
        }
        if (_keyToFreq.size() == _capacity) {
            removeMinFreqVal();
        }
        addNew(key, value);
    }

private:
    void incrFreq(int key) {
        int freq = _keyToFreq[key];
        list<int> tmp1;
        tmp1.swap(_freqToKeys[freq]);
        tmp1.remove(key);
        if (tmp1.empty()) {
            _freqToKeys.erase(freq);
            if (_minFreq == freq) {
                _minFreq += 1;
            }
        } else {
            _freqToKeys[freq].swap(tmp1);
        }
        if (!_freqToKeys.count(freq+1)) {
            _freqToKeys.insert(make_pair<int, list<int>>(freq+1, {}));
        }
        list<int> tmp2;
        tmp2.swap(_freqToKeys[freq+1]);
        tmp2.push_back(key);
        _freqToKeys[freq+1].swap(tmp2);
        _keyToFreq[key] += 1;
    }

    void removeMinFreqVal() {
        list<int> tmp;
        tmp.swap(_freqToKeys[_minFreq]);
        int key = tmp.front();
        tmp.pop_front();
        _keyToFreq.erase(key);
        _keyToVal.erase(key);
        if (tmp.empty()) {
            _freqToKeys.erase(_minFreq);
        } else {
            _freqToKeys[_minFreq].swap(tmp);
        }
    }

    void addNew(int key, int value) {
        _keyToVal[key] = value;
        _keyToFreq[key] = 1;
        if (!_freqToKeys.count(1)) {
            _freqToKeys.insert(make_pair<int, list<int>>(1, {key}));
        } else {
            list<int> tmp;
            tmp.swap(_freqToKeys[1]);
            tmp.push_back(key);
            _freqToKeys[1].swap(tmp);
        }
        _minFreq = 1;
    }
};

int main(int argc, char** argv)
{
    LFUCache* lfu = new LFUCache(2);
    lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
    lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
    lfu->get(1);      // 返回 1
//    /*
    // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu->put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
    // cache=[3,1], cnt(3)=1, cnt(1)=2
    lfu->get(2);      // 返回 -1（未找到）
    lfu->get(3);      // 返回 3
    // cache=[3,1], cnt(3)=2, cnt(1)=2
    lfu->put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
    // cache=[4,3], cnt(4)=1, cnt(3)=2
    lfu->get(1);      // 返回 -1（未找到）
    lfu->get(3);      // 返回 3
    // cache=[3,4], cnt(4)=1, cnt(3)=3
    lfu->get(4);      // 返回 4
    // cache=[3,4], cnt(4)=2, cnt(3)=3
//     */
    return 0;
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
