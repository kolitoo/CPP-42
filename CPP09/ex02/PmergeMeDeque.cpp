#include "PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque(char** av, int ac) : _av(av), _ac(ac) {}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& substitue) {
    if (this != &substitue)
        *this = substitue;
}

PmergeMeDeque::~PmergeMeDeque(void) {}

PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& substitue) {
    if (this != &substitue)
        *this = substitue;
    return (*this);
}

void mergeSort(std::deque<t_nbr>::iterator iter1, std::deque<t_nbr>::iterator iter2) {
    size_t size = iter2 - iter1;
    std::deque<t_nbr>::iterator iterMiddle = iter1 + size / 2;

    if (size > 1) {
        mergeSort(iter1, iterMiddle);
        mergeSort(iterMiddle, iter2);
        std::inplace_merge(iter1, iterMiddle, iter2);
    }
}

void PmergeMeDeque::CreatePending(void) {
    for (unsigned int i = 0; i < _PeerDeque.size(); i++) {
        if ((_ac - 1) % 2 != 0 && i == _PeerDeque.size() - 1) {
            _PendDeque.push_back(_PeerDeque[i]);
            _PeerDeque.pop_back();
        } else {
            if (_PeerDeque[i].peer != NULL) {
                _PendDeque.push_back(*_PeerDeque[i].peer);
                _PeerDeque[i].peer = NULL;
            }
        }
    }
}

void PmergeMeDeque::BinarySearch(void) {
    for (std::deque<t_nbr>::iterator it = _PendDeque.begin(); it != _PendDeque.end(); ++it) {
        t_nbr temp;
        temp.nb = it->nb;
        temp.peer = NULL;

        _PeerDeque.insert(std::upper_bound(_PeerDeque.begin(), _PeerDeque.end(), temp), temp);
    }
}

void PmergeMeDeque::CreateIntTab(void) {
    for (std::deque<t_nbr>::iterator it = _PeerDeque.begin(); it != _PeerDeque.end(); it++) {
        _IntDeque.push_back(it->nb);
    }
}

void PmergeMeDeque::SortDeque(void) {
    ParseAndPutInDeque();
    CreatePeer();
    if (((_ac - 1) % 2 == 0))
        mergeSort(_PeerDeque.begin(), _PeerDeque.end());
    else
        mergeSort(_PeerDeque.begin(), _PeerDeque.end() - 1);
    if (_ac > 2) {
        _PeerDeque.insert(_PeerDeque.begin(), *_PeerDeque[0].peer);
        _PeerDeque[0].peer = NULL;
        _PeerDeque[1].peer = NULL;
    }
    CreatePending();
    BinarySearch();
    CreateIntTab();
}

void PmergeMeDeque::CreatePeer(void) {
    for (unsigned int i = 0; i < _Array.size(); i += 2) {
        if (i == _Array.size() - 1) {
            _Array[i].peer = NULL;
            _PeerDeque.push_back(_Array[i]);
        } else {
            _Array[i].peer = &_Array[i + 1];
            _Array[i + 1].peer = &_Array[i];
            if (_Array[i].nb > _Array[i].peer->nb)
                _PeerDeque.push_back(_Array[i]);
            else
                _PeerDeque.push_back(_Array[i + 1]);
        }
    }
}

void PmergeMeDeque::ParseAndPutInDeque(void) {
    unsigned int i = 1;
    while (_av[i] != NULL) {
        std::string line = _av[i];
        CheckIfNumbers(line);
        t_nbr value;
        value.nb = std::atoi(line.c_str());
        if (value.nb > 2147483647)
            throw Overflow();
        _Array.push_back(value);
        i++;
    }
}

std::deque<int> PmergeMeDeque::GetArray(void) {
    return (_IntDeque);
}

void PmergeMeDeque::CheckIfNumbers(std::string nb) {
    if (nb == "")
        throw NotANumber();
    for (unsigned int i = 0; i < nb.size(); i++) {
        if (nb[i] < '0' || nb[i] > '9')
            throw NotANumber();
    }
}

const char* PmergeMeDeque::NotANumber::what(void) const throw() {
    return ("Error: Enter only Numbers.\n");
}

const char* PmergeMeDeque::Doublon::what(void) const throw() {
    return ("Error: Enter Differents Numbers.\n");
}

const char* PmergeMeDeque::Overflow::what(void) const throw() {
    return ("Error: Overflow.\n");
}
