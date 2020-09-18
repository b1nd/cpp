#include <stdexcept>

#include "PointArray.h"

namespace task2 {

PointArray::PointArray() : size_(0), arr_(nullptr) {}

PointArray::PointArray(const Point points[], Uint n) {
    // todo
    throw std::runtime_error("Not implemented!");
}

PointArray::PointArray(const PointArray& other) {
    // todo
    throw std::runtime_error("Not implemented!");
}

PointArray::PointArray(PointArray&& other) noexcept {
    // todo
    throw std::runtime_error("Not implemented!");
}

PointArray::~PointArray() {
    // todo
    throw std::runtime_error("Not implemented!");
}

void PointArray::append(const Point& pt) {
    // todo
    throw std::runtime_error("Not implemented!");
}

void PointArray::insert(const Point& pt, Uint pos) {
    // todo
    throw std::runtime_error("Not implemented!");
}

void PointArray::remove(Uint pos) {
    // todo
    throw std::runtime_error("Not implemented!");
}

void PointArray::clear() {
    // todo
    throw std::runtime_error("Not implemented!");
}

PointArray::Uint PointArray::getSize() const {
    return size_;
}

void PointArray::resize(Uint n) {
    // todo
    throw std::runtime_error("Not implemented!");
}

Point& PointArray::operator[](PointArray::Uint index) {
    // todo
    throw std::runtime_error("Not implemented!");
}

const Point& PointArray::operator[](PointArray::Uint index) const {
    // todo
    throw std::runtime_error("Not implemented!");
}

PointArray& PointArray::operator=(const PointArray& other) {
    // todo
    throw std::runtime_error("Not implemented!");

    return *this;
}

PointArray& PointArray::operator=(PointArray&& other) noexcept {
    // todo
    throw std::runtime_error("Not implemented!");

    return *this;
}

}