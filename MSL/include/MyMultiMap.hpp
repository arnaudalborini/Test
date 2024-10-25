#ifndef MYMULTIMAP_HPP
#define MYMULTIMAP_HPP

#include <map>
#include <vector>

template <typename T>
class MyMultiMap {
public:
    struct Key {
        int key1;
        int key2;
        bool operator<(const Key& other) const {
            return std::tie(key1, key2) < std::tie(other.key1, other.key2);
        }
    };

    void insert(int k1, int k2, const T& value) {
        data[Key{k1, k2}] = value;
    }

    T& at(int k1, int k2) {
        return data.at(Key{k1, k2});
    }

    const T& at(int k1, int k2) const {
        return data.at(Key{k1, k2});
    }

    // Opérateur [] pour accéder ou insérer
    T& operator[](const Key& key) {
        return data[key];
    }

    const T& operator[](const Key& key) const {
        return data.at(key);
    }

    // Méthode size pour obtenir le nombre d'éléments
    size_t size() const {
        return data.size();
    }

    std::map<int, T> getMapByKey1(int key1) const {
        std::map<int, T> result;
        for (const auto& pair : data) {
            if (pair.first.key1 == key1) {
                result[pair.first.key2] = pair.second;
            }
        }
        return result;
    }
private:
    std::map<Key, T> data;
};

#endif