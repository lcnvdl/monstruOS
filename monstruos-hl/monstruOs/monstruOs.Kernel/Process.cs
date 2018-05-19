using System;

namespace monstruOs.Kernel
{
    internal class Process : IDisposable
    {
        public ulong Id { get; private set; }

        public EProcessStatus Status { get; private set; }

        public EProcessType Type { get; private set; }

        public Process(ulong id)
        {
            this.Id = id;
            this.Status = EProcessStatus.Waiting;
        }

        public void Dispose()
        {
        }
    }
}
