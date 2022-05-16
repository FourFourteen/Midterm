

//You will need to complete two tasks.The tasks can be completed in any order you like.Submit the a link to the repository below.The repository MUST be public in order to be graded.
//
//1. Create a C++ project that displays the user a random multiple choice question.There should be at least 4 possible questions.Prompt the user for the answerand tell them if they are correct or not. (5 points)
//
//2. Create a public GitHub repository and push your code up to this repository. (5 points)
//
//
//
//Since you do not want to push binaryand compiled files into your repository, place the following code into a.gitignore file. (2 points)
//
//Debug
//Release
//ipch
//* .sdf
//* .opensdf
//* .db
//* .opendb
//* .suo
//* .exe
//!CreateMain.exe
/// UnitTester / Defines.h
//.vs

#include <iostream>
#include <string>
#include <vector>
void anyKey();
void question(std::vector<std::string>& questions, std::vector<int>& answerKey);

int main()
{
    srand(time(NULL));
    std::vector<std::string> questions{ "What color is NOT on the American Flag?\n1: Red\n2: Yellow\n3: White\n4: Blue\n", "How many sides does a pentagon have?\n1: Two Sides\n2: Three Sides\n3: Four Sides\n4: Five Sides\n",
    "How many degrees are in a circle?\n1: 90\n2: 180\n3: 270\n4: 360\n", "What is the first option in this question?\n1: This is the first option. You've got this!\n2: This is NOT the first option\n3: This is ALSO not the first option\n4: This is literally the furthest from the first option you can go. This isn't the answer.\n"};

    std::vector<int> answerKey{ 2,4,4,1 };

    while (!questions.empty()) {
        question(questions, answerKey);
    }
}


void anyKey() {
    std::cout << "\nPress any key to continue...";
    std::cin.get();
    system("CLS");
}

void question(std::vector<std::string>& questions, std::vector<int>& answerKey) {
    bool incorrect = true;
    int q = rand() % questions.size();
    while (incorrect) {
        std::cout << questions[q];
        std::string ans;
        std::getline(std::cin, ans);

        try {
            int convAns = std::stoi(ans);

            if (convAns < 1 || convAns > 4) {
                std::cout << "Number not in range, try again!" << std::endl;
                anyKey();
            }
            else {
                if (convAns == answerKey[q]) {
                    std::cout << "Correct!" << std::endl;
                    incorrect = false;
                }
                else {
                    std::cout << "Incorrect!" << std::endl;
                    incorrect = false;
                }
            }

        }
        catch (std::invalid_argument const& e) {
            std::cout << "Not a number. Try again!";
            anyKey();
        }
        catch (std::out_of_range const& e) {
            std::cout << "Number is too large! Try again!";
            anyKey();
        }
    }
    std::vector<int>::iterator it = answerKey.begin();
    std::vector<std::string>::iterator it2 = questions.begin();
    for (int i = 0; i < q; ++i) {
        it++;
        it2++;
    }
    answerKey.erase(it);
    questions.erase(it2);
    anyKey();

}
