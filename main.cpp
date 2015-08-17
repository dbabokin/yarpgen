/*
Copyright (c) 2015-2016, Intel Corporation

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "type.h"
#include "array.h"
#include "loop.h"
#include "operator.h"
#include "tree_elem.h"
#include "logic.h"

int main () {
/*
    Type a = Type (Type::TypeID::ULLINT);
    std::cout << a.get_id() << std::endl;
    std::cout << a.get_is_fp() << std::endl;
    std::cout << a.get_is_signed() << std::endl;
    std::cout << a.get_max_value() << std::endl;
    std::cout << a.get_min_value() << std::endl;
    a.set_max_value(ULLONG_MAX);
    a.set_min_value(ULLONG_MAX - 1);
    std::cout << a.get_max_value() << std::endl;
    std::cout << a.get_min_value() << std::endl;
    std::cout << a.get_rand_value() << std::endl;

    Array a ("a", Type::TypeID::ULLINT, 10);
    a.dbg_dump();
    std::cout << a.get_name()  << std::endl;
    std::cout << a.get_size()  << std::endl;
    a.set_size(100);
    std::cout << a.get_size()  << std::endl;
    std::cout << a.get_type_id()  << std::endl;
    std::cout << a.get_type_name()  << std::endl;
    std::cout << a.get_is_fp() << std::endl;
    std::cout << a.get_is_signed() << std::endl;
    std::cout << a.get_max_value() << std::endl;
    std::cout << a.get_min_value() << std::endl;
    a.set_max_value(ULLONG_MAX);
    a.set_min_value(ULLONG_MAX - 1);
    std::cout << a.get_max_value() << std::endl;
    std::cout << a.get_min_value() << std::endl;

    Loop a;
    a.dbg_dump ();
    std::cout << a.get_loop_type() << std::endl;
    a.set_loop_type (Loop::LoopType::WHILE);
    std::cout << a.get_loop_type() << std::endl;
    std::cout << a.get_iter_type_name() << std::endl;
    a.set_iter_type(Type::TypeID::UINT);
    std::cout << a.get_iter_type_id() << std::endl;
    std::cout << a.get_iter_type_name() << std::endl;
    std::cout << a.get_start_val() << std::endl;
    a.set_start_val(10);
    std::cout << a.get_start_val() << std::endl;
    std::cout << a.get_end_val() << std::endl;
    a.set_end_val(15);
    std::cout << a.get_end_val() << std::endl;
    std::cout << a.get_step() << std::endl;
    a.set_step(2);
    std::cout << a.get_step() << std::endl;
    std::cout << a.get_condition() << std::endl;
    a.set_condition (Loop::CondType::EQ);
    std::cout << a.get_condition() << std::endl;

    Operator a (0);
    std::cout << a.get_id () << std::endl;
    std::cout << a.get_name () << std::endl;
    std::cout << a.can_cause_ub () << std::endl;
    std::cout << a.get_num_of_op () << std::endl;
    Type t = Type (Type::TypeID::UINT);
    a.set_type (Operator::Side::LEFT, &t);
    std::cout << a.get_type_id (Operator::Side::LEFT) << std::endl;
    std::cout << a.get_type_name(Operator::Side::LEFT) << std::endl;
    std::cout << a.get_is_fp (Operator::Side::LEFT) << std::endl;
    std::cout << a.get_is_signed (Operator::Side::LEFT) << std::endl;
    std::cout << a.get_max_value (Operator::Side::LEFT) << std::endl;
    a.set_max_value (Operator::Side::LEFT, 20);
    std::cout << a.get_max_value (Operator::Side::LEFT) << std::endl;
    std::cout << a.get_min_value (Operator::Side::LEFT) << std::endl;
    a.set_min_value (Operator::Side::LEFT, 10);
    std::cout << a.get_min_value (Operator::Side::LEFT) << std::endl;
    a.dbg_dump();

    Array b ("b", Type::TypeID::ULLINT, 10);
    TreeElem c (true, NULL, Operator::OperType::MUL);
    c.dbg_dump();
    TreeElem a (false, &b, Operator::OperType::MAX_OPER_TYPE);
    a.dbg_dump();

    std::cout << a.get_is_op() << std::endl;
    std::cout << a.get_arr_name () << std::endl;
    std::cout << a.get_arr_size ()  << std::endl;
    std::cout << a.get_arr_type_name () << std::endl;
    std::cout << a.get_arr_max_value () << std::endl;
    a.set_arr_max_value (10);
    std::cout << a.get_arr_max_value () << std::endl;
    a.set_arr_min_value (2);
    std::cout << a.get_arr_min_value () << std::endl;
    std::cout << a.get_arr_is_fp () << std::endl;
    std::cout << a.get_arr_is_signed () << std::endl;
    std::cout << c.get_oper_id () << std::endl;
    std::cout << c.get_oper_name () << std::endl;
    std::cout << c.get_num_of_op () << std::endl;
    Type t = Type (Type::TypeID::UINT);
    c.set_oper_type(Operator::Side::LEFT, &t);
    std::cout << c.get_oper_type_id (Operator::Side::LEFT) << std::endl;
    std::cout << c.get_oper_type_name(Operator::Side::LEFT) << std::endl;
    std::cout << c.get_oper_type_is_fp (Operator::Side::LEFT) << std::endl;
    std::cout << c.get_oper_type_is_signed (Operator::Side::LEFT) << std::endl;
    std::cout << c.get_oper_max_value (Operator::Side::LEFT) << std::endl;
    c.set_oper_max_value (Operator::Side::LEFT, 20);
    std::cout << c.get_oper_max_value (Operator::Side::LEFT) << std::endl;
    std::cout << c.get_oper_min_value (Operator::Side::LEFT) << std::endl;
    c.set_oper_min_value (Operator::Side::LEFT, 10);
    std::cout << c.get_oper_min_value (Operator::Side::LEFT) << std::endl;
    std::cout << c.can_oper_cause_ub () << std::endl;
    c.dbg_dump();

    std::vector<Array> in;
    in.push_back(Array ("a1", 0, 2));
    in.push_back(Array ("a2", 2, 5));
    std::vector<Array> out;
    out.push_back(Array ("b", 1, 3));
    Statement a (0, &in, &out);
    std::cout << a.get_num_of_out () << std::endl;
    std::cout << a.get_depth () << std::endl;
    a.set_depth(5);
    std::cout << a.get_depth () << std::endl;
    std::cout << a.get_init_oper_type () << std::endl;
    a.set_init_oper_type (Operator::OperType::SUB);
    std::cout << a.get_init_oper_type () << std::endl;
    a.dbg_dump();
    a.random_fill ();
    a.dbg_dump();

    Type a = Type::get_rand_obj ();
    a.dbg_dump();

    Array a = Array::get_rand_obj ();
    a.dbg_dump();
    Array b = Array::get_rand_obj ();
    b.dbg_dump();

    Operator a = Operator::get_rand_obj ();
    a.dbg_dump();
*/
    TreeElem a = TreeElem::get_rand_obj_op ();
    a.dbg_dump();
}
