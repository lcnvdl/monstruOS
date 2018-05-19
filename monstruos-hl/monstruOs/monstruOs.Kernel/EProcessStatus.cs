using System;
using System.Collections.Generic;
using System.Text;

namespace monstruOs.Kernel
{
    internal enum EProcessStatus
    {
        Created,
        Waiting,
        Running,
        Blocked,
        Terminated
    }
}
