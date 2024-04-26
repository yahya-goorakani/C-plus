

#ifndef LABORATORY_WORK_2_QUEUEEXCEPTIONS_H
#define LABORATORY_WORK_2_QUEUEEXCEPTIONS_H

#include <exception>

namespace lab {

    class PopOutOfRange : public std::exception {
    public:
        [[nodiscard]] const char *what() const noexcept override {
            return "cannot pop an item from an empty queue";
        }
    };

}

#endif //LABORATORY_WORK_2_QUEUEEXCEPTIONS_H