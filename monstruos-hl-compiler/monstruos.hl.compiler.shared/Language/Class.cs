using System;
using System.Collections.Generic;
using System.Text;

namespace monstruos.hl.compiler.shared.Language
{
    public class Class : MetaObject
    {
        public override MetaType Type => MetaType.Class;

        public Class Parent { get; private set; }

        public List<Class> Children { get; private set; }

        public List<Interface> Implements { get; private set; }

        public Class()
        {
            Parent = null;
            Children = new List<Class>();
            Implements = new List<Interface>();
        }
    }
}
