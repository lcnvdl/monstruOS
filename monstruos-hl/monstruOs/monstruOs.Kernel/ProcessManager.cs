using System;
using System.Collections.Generic;
using System.Text;

namespace monstruOs.Kernel
{
    internal class ProcessManager
    {
        private Queue<Process> waitQueue;
        private Queue<Process> runQueue;

        public bool IsMultiProcess
        {
            get
            {
                return true;
            }
        }

        public int MaxRunningProccesses { get; set; }

        public ProcessManager()
        {
            waitQueue = new Queue<Process>();
            runQueue = new Queue<Process>();
        }

        public void Add(Process process)
        {
            waitQueue.Enqueue(process);
        }

        public void Loop()
        {
            RemoveTerminatedProcesses();
            RunCreatedProcesses();
        }

        private void RunCreatedProcesses()
        {
            int slots = MaxRunningProccesses - runQueue.Count;

            while (slots > 0 && waitQueue.Count > 0)
            {
                Process process = waitQueue.Dequeue();
                runQueue.Enqueue(process);
                slots = MaxRunningProccesses - runQueue.Count;
            }
        }

        private void RemoveTerminatedProcesses()
        {
            RemoveAll(waitQueue, p => 
            {
                if (p.Status == EProcessStatus.Terminated)
                {
                    p.Dispose();
                    return true;
                }

                return false;
            });

            RemoveAll(runQueue, p => 
            {
                if (p.Status == EProcessStatus.Terminated)
                {
                    waitQueue.Enqueue(p);
                    return true;
                }

                return false;
            });
        }

        private void RemoveAll(Queue<Process> queue, Func<Process, bool> req)
        {
            Process first = queue.Dequeue();
            queue.Enqueue(first);
            Process current;

            do
            {
                current = queue.Dequeue();
                if (!req(current))
                {
                    queue.Enqueue(current);
                }
            }
            while (current != first);
        }
    }
}
