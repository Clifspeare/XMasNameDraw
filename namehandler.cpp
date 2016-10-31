/*
 * Copyright (c) 2016, Spencer Brown <spencerbrown991@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Spencer Brown <spencerbrown991@gmail.com> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Spencer Brown <spencerbrown991@gmail.com> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "namehandler.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <cstdlib>

bool NameHandler::isexcluded(std::string giver, std::string recipient, const std::vector< std::pair<std::string, std::string> > &exclusions)
{
    /*if (giver == recipient) {
        return true;
    } else {
        for (auto &c : exclusions) {
            if (((giver == c.first) && (recipient == c.second)) || ((giver == c.second) && (recipient == c.first))) {
                return true;
            }
        }
        return false;
    }
    return false;*/
    if (giver == recipient) {
        return true;
    } else if (this->assigned.find(recipient) != assigned.end()) {
        return true;
    } else {
        for (auto &c : exclusions) {
            if (((giver == c.first) && (recipient == c.second)) || ((giver == c.second) && (recipient == c.first))) {
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
}

void NameHandler::drawNames(const std::vector<std::pair<std::string, std::string> > &excludedNames)
{
    //std::string santa;
    std::string recipient;
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> uint_dist(0, names.size() - 1);
    std::cout << "Great!" << std::endl << "Now we can start the process of drawing names for each secret santa participant." << std::endl;
    std::system("clear");
    for (auto &p : names) {
        std::cout << p << ", please come to the computer.  Press enter when ready, but make sure no one else is watching! ;)" << std::endl;
        recipient = p;
        std::cin.get();
        while (isexcluded(p, recipient, excludedNames)) {
            recipient = names.at(uint_dist(rng));
        }
        this->assigned.emplace(recipient, p);
        std::cout << "Your secret santa gift recipient is: " << recipient << std::endl;
        //^std::cout << "We're about to give you your secret santa recipient name" << std::endl;^
        std::cout << "Before you leave, don't forget to write it down; we won't remember it for you." << std::endl;
        std::cout << "You see..." << std::endl;
        std::cout << "Computers are bad at keeping secrets :(" << std::endl;
        std::cout << "After you've written your gift recipients name down, hit enter and we'll erase it from the screen. " << "Then we'll call the next participant."  << std::endl;
        //std::cout << "Your secret santa gift recipient is: " << recipient;
        std::cout.flush();
        std::cin.get();
        std::system("clear");

    }
}

void NameHandler::getNames()
{
    std::string name;
    std::cout << "Please enter each name to be entered into the drawing" << std::endl;
    std::cout << "If you type a name incorrectly, enter \"undo\"" << std::endl;
    std::cout << "When finished, type done" << std::endl;
    while (true) {
        std::getline(std::cin, name);
        if (!std::cin.good()) {
            break;
        } else if (name == "undo") {
            if (names.size() != 0) {
                names.pop_back();
            }
            //remove the last item from entered names
        } else if (name == "done") {
            break;
        } else {
            names.push_back(name);
        }
    }
}
