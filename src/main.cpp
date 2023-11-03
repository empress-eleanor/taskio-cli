#include "utils.hpp"
#include <iostream>
#include <limits>
#include <string>

#define TASK_LIMIT 100

#define NORMAL "\033[39m"
#define INFO "\033[94m"
#define SUCCESS "\033[92m"
#define ERROR "\033[91m"

class Task
{
private:
  std::string mName;
  int mId,
      mStatus; /* 0 = incomplete, 1 = complete */

public:
  Task()
      : mName(INFO "Unknown" NORMAL), mStatus(0)
  {
  }

  const std::string &getName() const
  {
    return this->mName;
  }

  void changeName(const std::string &name)
  {
    this->mName = name;
  }

  int &getId()
  {
    return mId;
  }

  void setId(const int &id)
  {
    this->mId = id;
  }

  int &getStatus()
  {
    return mStatus;
  }

  void setStatus(const int &status)
  {
    this->mStatus = status;
  }
};

int main()
{
  Task task[TASK_LIMIT];
  int counter = 0;

  std::string taskName;
  int taskId;

  int option;

  do
  {
    clearScreen();

    std::cout << "1. Add a task\n";
    std::cout << "2. Mark a task as completed\n";
    std::cout << "3. List all task\n";
    std::cout << "0. Exit the application\n";
    std::cout << INFO "Enter your choice: " NORMAL;

    if (!(std::cin >> option))
    {
      option = -1;
    }

    switch (option)
    {
      /* Add a task */
    case 1:
      clearScreen();

      if (counter == TASK_LIMIT)
      {
        std::cout << INFO "Your task store is full\nPress enter to continue" NORMAL;
        waitForEnter();
        break;
      }

      std::cout << INFO "Enter the name of task: " NORMAL;
      std::cin.ignore();
      std::getline(std::cin, taskName);

      if (taskName == "")
      {
        std::cout << ERROR "invalid name" NORMAL << std::endl;
        break;
      }

      task[counter].changeName(taskName);
      task[counter].setId(counter);

      counter++;

      std::cout << SUCCESS "Task added successfully\nPress Enter to continue" NORMAL;

      // Wait for user to press enter
      std::cin.clear();
      std::cin.get();
      break;

      /* Mark task as completed */
    case 2:
      clearScreen();

      if (counter == 0)
      {
        std::cout << INFO "There is no task\nPress enter to continue\n" NORMAL;
        waitForEnter();
        break;
      }

      std::cout << INFO "Enter the Id of the task to mark as completed: " NORMAL;
      std::cin >> taskId;

      if (taskId >= counter || taskId < 0)
      {
        std::cout << INFO "Following task does not exist\n" NORMAL;
        waitForEnter();
        break;
      }

      if (task[taskId].getStatus() == 1)
      {
        std::cout << INFO "Following task is already completed\n" NORMAL;
        waitForEnter();
        break;
      }

      task[taskId].setStatus(1);
      std::cout << SUCCESS "Successfully marked task as completed\n" NORMAL;
      waitForEnter();
      break;

      /* List all task */
    case 3:
      clearScreen();

      if (counter == 0)
      {
        std::cout << INFO "There is no task\nPress enter to continue\n" NORMAL;
        waitForEnter();
        break;
      }

      std::cout << SUCCESS "ID "
                << " "
                << truncateString("Name", 30) << " "
                << truncateString("Status", 10) << NORMAL << std::endl;

      for (int i = 0; i < counter; ++i)
      {
        std::string id = std::to_string(task[i].getId());
        std::string name = task[i].getName();
        std::string status = task[i].getStatus() == 0 ? ERROR "Incomplete" NORMAL : SUCCESS "Complete" NORMAL;

        std::cout
            << truncateString(id, 3) << " "
            << truncateString(name, 30) << " "
            << status << std::endl;
      }

      waitForEnter();
      break;

      /* Exit from the app */
    case 0:
      clearScreen();
      std::cout << SUCCESS "Thank you for using our program\nPress Enter to continue" NORMAL << std::endl;
      waitForEnter();
      break;

      /* Invalid user choice */
    default:
      clearScreen();
      std::cout << ERROR "Invalid Option\nPress Enter to continue" NORMAL << std::endl;
      waitForEnter();
      break;
    }
  } while (option != 0);

  return EXIT_SUCCESS;
}
