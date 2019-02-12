//
// Created by sriteja on 10/2/19.
//

#include "TwoDPolygon.h"
#include "main.h"

TwoDPolygon::TwoDPolygon(int num_of_sides, GLfloat *coordinates, glm::vec3 position, color_t color, glm::vec3 scale_values,
                         float rotation_angle, glm::vec3 rotation_axis) {
    std::cout << "num_sides " << num_of_sides << std::endl;

    this->num_of_sides = num_of_sides;
    this->position = position;
    this->rotation = rotation_angle;
    this->scale = scale_values;
    this->rotation_axis = rotation_axis;
    convertCoordinatesToVertices(coordinates, num_of_sides, this->vertices);
    construct(this->vertices);
    this->color = color;
    this->object = create3DObject(GL_TRIANGLES, 3*num_of_sides, this->vertex_data, color, GL_FILL);

    model_matrix = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate(glm::radians(this->rotation), this->rotation_axis);
    glm::mat4 scale_mat = glm::scale(this->scale);

    model_matrix *= (translate*rotate*scale_mat);

}

void TwoDPolygon::convertCoordinatesToVertices(GLfloat *coordinates, int n, glm::vec3 *vertices) {
    std::cout << "coor " << coordinates[3] << std::endl;
    for (int i=0,j=0; i<3*n; i+=3, j++) {
        vertices[j] = glm::vec3(coordinates[i], coordinates[i + 1], coordinates[i + 2]);
    }
    std::cout << vertices[1].x << std::endl;
//    for (auto i = vertices[1].begin(); i != path.end(); ++i)
//        std::cout << *i << ' ';
}

void TwoDPolygon::findCentroid() {
    float sum_x=0, sum_y=0, sum_z=0;
    std::cout << this->vertices[1].x << std::endl;
    for (int i=0; i<this->num_of_sides; i++)
    {
        sum_x += this->vertices[i].x;
        sum_y += this->vertices[i].y;
        sum_z += this->vertices[i].z;
    }
    centroid.x = sum_x/float(this->num_of_sides);
    centroid.y = sum_y/float(this->num_of_sides);
    centroid.z = sum_z/float(this->num_of_sides);
    std::cout << "sum " << sum_x << ' ' << sum_y << ' ' << sum_z;
}

void TwoDPolygon::copyVectorToArray(glm::vec3 vect, GLfloat *arr, int index) {
    arr[index++] = vect.x;
    arr[index++] = vect.y;
    arr[index] = vect.z;
}

void TwoDPolygon::print_array(GLfloat *arr) {
    int start=0;
    for (int i=0;i<this->num_of_sides;i++)
    {
        for (int j=0;j<3;j++) {
            for (int k=0;k<3;k++)
                printf("%f ",arr[start++] );
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");

}

void TwoDPolygon::construct(glm::vec3 vertices[]) {
    findCentroid();

    int i=0, j=1;
    int k=0;
    for(;i<this->num_of_sides;i++,j++) {

        copyVectorToArray(this->centroid, this->vertex_data, k);
        k += 3;

        copyVectorToArray(vertices[i], this->vertex_data, k);
        k += 3;

        copyVectorToArray(vertices[j%this->num_of_sides], this->vertex_data, k);
        k += 3;
    }

    print_array(this->vertex_data);
//    std::cout << "Centroid " << centroid.x << ' ' << centroid.y << centroid.z << std::endl;
}

void TwoDPolygon::draw(glm::mat4 VP, bool reflect) {
//    Matrices.model = glm::mat4(1.0f);
//    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
//    glm::mat4 rotate    = glm::rotate(glm::radians(this->rotation), this->rotation_axis);
//    glm::mat4 scale_mat = glm::scale(this->scale);
//    glm::mat4 ref_mat = glm::mat4(1.0f);
//    if (reflect) {
//        ref_mat[0] = glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f);
//        ref_mat[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
//        ref_mat[2] = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f);
//        ref_mat[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
//    }
////    glm::mat4 reflection = glm::reflect(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//    // No need as coords centered at 0, 0, 0 of cube around which we want to rotate
////     rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
//    Matrices.model *= (translate*rotate*scale_mat*ref_mat);
//    printf("                 Start              \n");
//    for (int i=0;i<4;i++) {
//        printf("%f %f %f %f\n", Matrices.model[i].x, Matrices.model[i].y, Matrices.model[i].z, Matrices.model[i].w);
//    }
//    printf("\n");
//    for (int i=0;i<4;i++) {
//        printf("%f %f %f %f\n", model_matrix[i].x, model_matrix[i].y, model_matrix[i].z, model_matrix[i].w);
//    }
//    exit(0);
//    model_matrix *= translate;
    glm::mat4 MVP = VP * model_matrix;
//    model_matrix *= glm::inverse(translate);
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
//    print_array(this-)
    draw3DObject(this->object);

}


void TwoDPolygon::model(glm::vec3 axis) {
    printf("                 Start              \n");
    axis = glm::vec3(1,1,0);
    glm::mat4 rot (1.0f);
    for (int i=0;i<4;i++) {
        printf("%f %f %f %f\n", rot[i].x, rot[i].y, rot[i].z, rot[i].w);
    }
    rot[0] = glm::vec4(axis.x, axis.y, axis.z, 0);
    glm::vec3 temp = glm::cross(axis, glm::vec3(1, 0, 0));
    rot[1] = glm::vec4(temp.x, temp.y, temp.z, 0);
    glm::vec3 temp2 = glm::cross(axis, temp);
    rot[2] = glm::vec4(temp2.x, temp2.y, temp2.z, 0);

    glm::mat4 rotate_x = glm::rotate(glm::radians(1.0f), glm::vec3(1,0,0));
    glm::mat4 inverse = glm::inverse(rot);


    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
//    glm::mat4 rotate    = glm::rotate(glm::radians(this->rotation), this->rotation_axis);
    glm::mat4 scale_mat = glm::scale(this->scale);
//    model_matrix  = translate * inverse * rotate_x * rot;
//    exit(0);


}


void TwoDPolygon::rotate(float angle, glm::vec3  point, glm::vec3 axis) {
//    point = glm::vec3(0);
    glm::mat4 translate = glm::translate(-point-this->position);
    glm::mat4 rotate_mat = glm::rotate(glm::radians(angle), axis);
    glm::mat4 translate_inv = glm::translate(point+this->position);

    glm::mat4 total = translate_inv * rotate_mat * translate;
//    glm::mat4 translate_inv = glm::inverse(translate);
    model_matrix = total * model_matrix;

    glm::vec4 temp =  total * glm::vec4(position.x, position.y, position.z, 1);
//    position  = temp;
//    this->position.x = temp.x;
//    this->position.y = temp.y;
//    this->position.z = temp.z;

    printf("start\n%f %f %f %f\n",temp.x, temp.y, temp.z, temp.w);
    printf("start\n%f %f %f\n",position.x, position.y, position.z);
//    exit(0);
//    model_matrix = (rotate_mat) * model_matrix;
//    position += point;
//    glm::vec4 temp = rotate_mat * glm::vec4(position.x, position.y, position.z, 1);
//    position = glm::vec3(temp.x, temp.y, temp.z);
}

void TwoDPolygon::update_position(glm::vec3 change) {
    printf("start\n");
    printf("%f %f %f\n",change.x, change.y, change.z);
    printf("%f %f %f\n", position.x, position.y, position.z);
    this->position += change;
    printf("%f %f %f\n", position.x, position.y, position.z);
    glm::mat4 translate = glm::translate (change);

    printf("\n\n");
    for (int i=0;i<4;i++) {
        printf("%f %f %f %f\n", model_matrix[i].x, model_matrix[i].y, model_matrix[i].z, model_matrix[i].w);
    }
    this->model_matrix = translate * model_matrix;
    printf("\n");
    for (int i=0;i<4;i++) {
        printf("%f %f %f %f\n", model_matrix[i].x, model_matrix[i].y, model_matrix[i].z, model_matrix[i].w);
    }
    printf("\n");
    for (int i=0;i<4;i++) {
        printf("%f %f %f %f\n", translate[i].x, translate[i].y, translate[i].z, translate[i].w);
    }
//    exit(0);
}


void TwoDPolygon::reflect(glm::vec3 axis) {
    glm::mat4 ref_mat;
    ref_mat[0] = glm::vec4(-1.0f, 0.0f, 0.0f, 0.0f);
    ref_mat[1] = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
    ref_mat[2] = glm::vec4(0.0f, 0.0f, -1.0f, 0.0f);
    ref_mat[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
    model_matrix =  model_matrix  * ref_mat;
}