// Copyright (C) 2023 by iamslash

import java.util.*;

// 68ms 55.56% 44.9MB 73.02%
// hash map, hash set
//        addTask: O(N)
//    getAllTasks: O(N)
// getTasksForTag: O(N)
//   completeTask: O(1)
class Task {
    int taskId;
    String description;
    int due;
    Set<String> tagSet;
    public Task(int taskId, String description, int duedate, List<String> tags) {
        this.taskId = taskId;
        this.description = description;
        this.due = duedate;
        this.tagSet = new HashSet<>(tags);
    }
}
class TodoList {
    int seq = 1;
    Map<Integer, TreeSet<Task>> userTasksMap = new HashMap<>();
    Map<Integer, Task> idTaskMap = new HashMap<>();

    public int addTask(int userId, String taskDescription, int dueDate, List<String> tags) {
        Task task = new Task(seq, taskDescription, dueDate, tags);
        idTaskMap.put(seq, task);
        userTasksMap.putIfAbsent(userId, new TreeSet<>((a, b) -> a.due == b.due ? a.taskId - b.taskId : a.due - b.due));
        userTasksMap.get(userId).add(task);
        return seq++;
    }
    
    public List<String> getAllTasks(int userId) {
        List<String> rst = new ArrayList<>();
        if (!userTasksMap.containsKey(userId)) {
            return rst;
        }
        for (Task task : userTasksMap.get(userId)) {
            rst.add(task.description);
        }
        return rst;
    }
    
    public List<String> getTasksForTag(int userId, String tag) {
        List<String> rst = new ArrayList<>();
        if (!userTasksMap.containsKey(userId)) {
            return rst;
        }
        for (Task task : userTasksMap.get(userId)) {
            if (task.tagSet.contains(tag)) {
                rst.add(task.description);
            }
        }
        return rst;
    }
    
    public void completeTask(int userId, int taskId) {
        if (!idTaskMap.containsKey(taskId) ||
            !userTasksMap.containsKey(userId)) {
            return;
        }
        Task task = idTaskMap.get(taskId);
        if (userTasksMap.get(userId).contains(task)) {
            userTasksMap.get(userId).remove(task);
            idTaskMap.remove(taskId);
        }
    }
}
