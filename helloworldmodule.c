#include <Python.h>

static PyObject *helloworldError;

static PyObject* helloworldTalk(PyObject* self, PyObject *args) {
        const char *msg;

        if(!PyArg_ParseTuple(args, "s", &msg)) {
                PyErr_SetString(helloworldError, "Failed to parse args.");
                return NULL;
        }

        if(strlen(msg) == 0) {
                return Py_BuildValue("s", "Hello, World!");
        } else {
                return Py_BuildValue("s", msg);
        }
}

static PyMethodDef helloworld_methods[] = {
        // Python name    C-function name       arg flag        desc
        {"talk", helloworldTalk, METH_VARARGS, "If string len is 0 it returns 'Hello, World!', else it passes back the string"},
        {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inithelloworld(void) {
    PyObject *module;
    module = Py_InitModule("helloworld", helloworld_methods);
    if(module == NULL) return;

    helloworldError = PyErr_NewException("helloworld.error", NULL, NULL);
    Py_INCREF(helloworldError);

    PyModule_AddObject(module, "error", helloworldError);
}
