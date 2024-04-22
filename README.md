# philosophers

**Quick start**
- Compile: make (in the folder with the Makefile)
- Run: ./philo 4 400 300 200 (for example)

**Project Documentation - Dining Philosophers**

**1. Introduction:**
The Dining Philosophers problem is a classic synchronization problem in concurrent programming. It involves a group of philosophers sitting around a round table, with a bowl of spaghetti in the middle and forks placed between each pair of neighboring philosophers. The philosophers alternate between eating, thinking, and sleeping. To eat, a philosopher needs both the fork on their left and the fork on their right.

**2. Project Overview:**
The goal of this project is to simulate the behavior of the Dining Philosophers using threads and mutexes in C. The program, named "philo," takes several command-line arguments and follows specific rules to ensure the philosophers eat and avoid starving.

**3. Project Requirements:**
The program "philo" takes the following command-line arguments:
- `number_of_philosophers`: The number of philosophers (and forks) sitting around the table.
- `time_to_die`: The maximum time in milliseconds a philosopher can go without eating before they die of starvation.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to eat, during which they must hold both forks.
- `time_to_sleep`: The time in milliseconds a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]` (optional): The number of times each philosopher must eat. If not specified, the simulation stops when a philosopher dies.

**4. Global Rules and Constraints:**
- Global variables are not allowed.
- Each philosopher is represented by a thread.
- Each philosopher has a number ranging from 1 to `number_of_philosophers`.
- Philosopher 1 sits next to philosopher `number_of_philosophers`, and any other philosopher `N` sits between philosopher `N-1` and philosopher `N+1`.
- Philosopher N holds a fork on their left side (fork N-1) and a fork on their right side (fork N).
- Philosopher states and actions must be logged with timestamps.

**5. Logging and State Changes:**
- Each state change of a philosopher must be formatted as follows:
  - `timestamp_in_ms X has taken a fork`
  - `timestamp_in_ms X is eating`
  - `timestamp_in_ms X is sleeping`
  - `timestamp_in_ms X is thinking`
  - `timestamp_in_ms X died`
  (Replace `timestamp_in_ms` with the current timestamp in milliseconds and `X` with the philosopher number.)
- A displayed state message should not be mixed up with another message.
- A message announcing a philosopher's death should be displayed no more than 10 ms after the actual death.

**6. Mandatory Part:**
- Each philosopher should be a separate thread.
- One fork should be placed between each pair of philosophers, and they must be protected with a mutex to avoid duplication.

**7. Functions Allowed:**
The project can use the following external functions:
- `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.

**8. Makefile:**
The project should include a Makefile with the following targets: `all`, `clean`, `fclean`, and `re` for building, cleaning, and recompiling the project.

**9. Execution:**
To run the "philo" program, provide the necessary command-line arguments such as the number of philosophers, time constraints, and an optional argument for the number of times each philosopher must eat. The program will simulate the dining philosophers problem, displaying their actions and state changes with timestamps.

**10. Conclusion:**
In conclusion, the "philo" program effectively simulates the behavior of philosophers dining around a table, using threads and mutexes to ensure synchronization and avoid any issues with shared resources. By adhering to the specified rules and constraints, the simulation accurately models the interactions between the philosophers and their dining process, providing insight into concurrent programming challenges.
