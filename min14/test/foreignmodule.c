#define PY_SSIZE_T_CLEAN
#include <Python.h>


static PyObject *foreign_message_to_c(PyObject *self, PyObject *args) {
const char *text;
    if (!PyArg_ParseTuple(args, "s", &text)) {
        return NULL;
    }
    printf("Message from Python world: %s", text);
    return PyLong_FromLong(0);
}
static PyMethodDef ForeignMethods[] = {
    {"message_to_c",
     foreign_message_to_c, METH_VARARGS,
     "Print the specified string from C code."
    },
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef foreignmodule = {
    PyModuleDef_HEAD_INIT,
    "foreign", /* name of module */
    NULL, /* module documentation, may be NULL */
    -1, /* size of per-interpreter state of the module,
    or -1 if the module keeps state in global variables. */
    ForeignMethods
};
PyMODINIT_FUNC PyInit_foreign(void) {
return PyModule_Create(&foreignmodule);
}