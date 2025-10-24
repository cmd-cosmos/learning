#pylint: skip-file

import asyncio

class Job:
    def __init__(self, id, waitTime) -> None:
        self.id = id
        self.waitTime = waitTime

    def __repr__(self) -> str:
        return f"Job(id={self.id}, waitTime={self.waitTime})"        

class Multiprogramming:
    def __init__(self, num_jobs, job_list) -> None:
        self.num_jobs = num_jobs
        self.job_list = job_list
    
    def submitJobs(self):
        for job in self.job_list:
            print("Submitted: ", job)
    
    async def runJob(self, job):
        print("Starting:  ", job)
        await asyncio.sleep(job.waitTime)
        print("Completed: ", job)
    
class Multitasking(Multiprogramming):
    def __init__(self, num_jobs, job_list, user) -> None:
        super().__init__(num_jobs, job_list)
        self.user = user

class TimeSharing(Multiprogramming):
    def __init__(self, num_jobs, job_list, users) -> None:
        super().__init__(num_jobs, job_list)
        self.users = users

    def timeAlloc(self):
        for user in self.users:
            print("Allocating time to user: ", user)


j1 = Job(id=1, waitTime=2)
j2 = Job(id=2, waitTime=5)
j3 = Job(id=3, waitTime=1)
j4 = Job(id=4, waitTime=3)
j5 = Job(id=5, waitTime=10)

job_list = [j1, j2, j3, j4, j5]

