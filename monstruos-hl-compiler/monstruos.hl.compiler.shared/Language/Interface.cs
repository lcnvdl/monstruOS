using System;
using System.Collections.Generic;

namespace monstruos.hl.compiler.shared.Language
{
    public class Interface : MetaObject
    {
        public override MetaType Type => MetaType.Interface;

        public List<Interface> Implements { get; private set; }

        public Interface()
        {
            Implements = new List<Interface>();
        }

    }
}
