/*
** EPITECH PROJECT, 2020
** G-JAM-001-MAR-0-2-jam-killian.moudery
** File description:
** SafeQueue.hpp
*/

#ifndef SAFEQUEUE_HPP_
#define SAFEQUEUE_HPP_

#include <atomic>
#include <array>

// Thread-safe queue for insertion (capacity of 256 elements)
template<class T>
class SafeQueue {
public:
    SafeQueue() : writeIdx(0), count(0) {}
    ~SafeQueue() = default;
    // Insert element to thread-safe queue, return true on success
    bool push(T &data) {
        if (++count > 256) {
            --count;
            return false;
        }
        datas[++writeIdx] = std::move(data);
        return true;
    }
    bool pushCpy(T data) {
        return push(data);
    }
    // Extract element from queue, return true on success
    bool pop(T &data) {
        if (count) {
            data = std::move(datas[++readIdx]);
            --count;
            return true;
        }
        return false;
    }
    bool empty() const {
        return count == 0;
    }
private:
    T datas[256];
    unsigned char readIdx = 0;
    std::atomic<unsigned char> writeIdx;
    std::atomic<unsigned short> count;
};

#endif /* SAFEQUEUE_HPP_ */
