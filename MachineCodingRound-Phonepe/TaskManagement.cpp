#include "./includes/managers/UserManager.hpp"
#include "./includes/managers/ProjectManager.hpp"
#include "./includes/managers/WorkloadManager.hpp"

#include "./includes/model/Task.hpp"
#include "./includes/model/Story.hpp"

#include <iostream>

int main() {

    ProjectManager& projectManager = ProjectManager::getInstance();

    // Create users and add them to the user manager
    UserManager& userManager = UserManager::getInstance();
    userManager.addUser("user1", "password1");
    userManager.addUser("user2", "password2");

    // Authenticate users
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    if (userManager.authenticate(username, password)) {
        std::cout << "Authentication successful!\n";
        
        User* user1 = userManager.getUser(username);
        User* user2 = userManager.getUser("user2");

        Project* project = projectManager.createComponent("Project1", "2024-06-30", *user1);
        
        if(project)
        {
            StoryManager* storyManager = projectManager.getStoryManager(project->getId());
            TaskManager* taskManager = projectManager.getTaskManager(project->getId());
            SubTaskManager* subTaskManager = projectManager.getSubTaskManager(project->getId());


            if(storyManager && taskManager && subTaskManager)
            {
                Story* story1 = storyManager->createComponent("Story1", "2024-03-30", *user1, project);
                Story* story2 = storyManager->createComponent("Story2", "2024-05-30", *user2, project);   

                if(story1)
                {
                    Task* task1 = taskManager->createComponent("Task1", "2024-02-28", *user2, story1);
                    Task* task2 = taskManager->createComponent("Task2", "2024-03-25", *user2, story1);
                    if(task1)
                    {
                        Task* subtask1 = subTaskManager->createComponent("SubTask1","2024-02-25",*user2,task1);
                        Task* subtask2 = subTaskManager->createComponent("SubTask2","2024-02-28",*user2,task1);
                    }
    
                }
                if(story2)
                {
                    Task* task1 = taskManager->createComponent("Task1", "2024-04-28", *user1, story2);
                    Task* task2 = taskManager->createComponent("Task2", "2024-05-25", *user1, story2);    
                }

                std::cout<<"Story 1"<<std::endl;
                story1->display();
                std::cout<<std::endl;

                std::cout<<"Story 2"<<std::endl;
                story2->display();
                std::cout<<std::endl;   

                          
            }
        }

        // // Display task states
        // std::cout << "Task 1 Status: ";
        // switch (task1->getStatus()) {
        //     case Task::Status::TO_DO:
        //         std::cout << "To Do\n";
        //         break;
        //     case Task::Status::PENDING:
        //         std::cout << "Pending\n";
        //         break;
        //     case Task::Status::DONE:
        //         std::cout << "Done\n";
        //         break;
        // }

        // std::cout << "Task 2 Status: ";
        // switch (task2->getStatus()) {
        //     case Task::Status::TO_DO:
        //         std::cout << "To Do\n";
        //         break;
        //     case Task::Status::PENDING:
        //         std::cout << "Pending\n";
        //         break;
        //     case Task::Status::DONE:
        //         std::cout << "Done\n";
        //         break;
        // }

        // Track tasks for workload --> not working
        // WorkloadManager& tracker = WorkloadManager::getInstance();
        // tracker.trackTask(*user, *task1)
        // ;
        // tracker.trackTask(*user, *task2);

        //  // Display workload
        // std::cout << "Workload for " << username << ": "<< std::endl;
        // tracker.getWorkload(*user) ;
    } else {
        std::cout << "Authentication failed. Invalid username or password.\n";
    }

    return 0;
}