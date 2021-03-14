#ifndef GCP_ICP_COLLECTIONS_H
#define GCP_ICP_COLLECTIONS_H

#include <QMainWindow>

namespace Ui {
class GCP_ICP_collections;
}

class GCP_ICP_collections : public QMainWindow
{
    Q_OBJECT

public:
    explicit GCP_ICP_collections(QWidget *parent = nullptr);
    ~GCP_ICP_collections();

private:
    Ui::GCP_ICP_collections *ui;
};

#endif // GCP_ICP_COLLECTIONS_H
