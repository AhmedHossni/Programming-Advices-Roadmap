using System;
using System.Collections.Generic;
using System.Text;

namespace Hadhoad_Course__13__All_Projects__C__
{
    public class clsStringWithUndoAndRedo
    {
        private string _value = string.Empty;
        Stack<string> _undoStack { get; set; } = new Stack<string>();
        Stack<string> _redoStack { get; set; } = new Stack<string>();
        public string Value
        { 
            get => _value;
            
            set
            {
                _undoStack.Push(_value);
                _value = value;
            }
        }


        public void Undo()
        {
            if (!_undoStack.Any())
                return;

            _redoStack.Push(_value);

            _value = _undoStack.Pop();

        }

        public void Redo()
        {
            if (!_redoStack.Any())
                return;

            _undoStack.Push(_value);

            _value = _redoStack.Pop();

        }
    }
}
