#include "game.hpp"
void RMIDlet::__clinit() {
   __inited = true;
}
RMIDlet::RMIDlet() {
}
void RMIDlet::startApp() {
   if (((o::__ci(),o::a_MIDlet) == nullptr)) {
      ((o::__ci(),o::a_MIDlet) = this);
      (o::__ci(), o::h_i_v(1));
   } else {
      (o::__ci(), o::h_i_v(3));
   }
}
void RMIDlet::pauseApp() {
   (o::__ci(), o::h_i_v(2));
   this->notifyPaused();
}
void RMIDlet::destroyApp(bool L_var1) {
   (o::__ci(), o::a__v());
}
void j::__clinit() {
   __inited = true;
   a_d = (d::__ci(), new d());
   a_i = 0;
   f_d = (d::__ci(), new d());
   i_d = (d::__ci(), new d());
   g_d = (d::__ci(), new d());
   j_d = (d::__ci(), new d());
   k_d = (d::__ci(), new d());
   (j::g_d->a_i = 43266);
   (j::g_d->e_i = (-43266));
   if (((o::__ci(),o::b_i) < 200)) {
      (j::g_d->a_i = 22306);
      (j::g_d->e_i = (-22306));
   }
   (j::b_i = 0);
   (j::a_Aj = newArr<j*>(60));
   (j::b_j = (j::__ci(), new j()));
}
j::j() {
   this->e_z = true;
   this->a_z = true;
   this->f_z = true;
   this->g_z = true;
   this->c_b = ((int8_t)(1));
   ([&]() -> decltype(auto) { auto& __a1 = this->c_s; auto __v2 = (j::d_s++); return (__a1 = __v2); }());
   ([&]() -> decltype(auto) { auto& __a3 = this->b_d; auto __v4 = (d::__ci(), new d()); return (__a3 = __v4); }());
   ([&]() -> decltype(auto) { auto& __a5 = this->c_d; auto __v6 = (d::__ci(), new d()); return (__a5 = __v6); }());
   ([&]() -> decltype(auto) { auto& __a7 = this->h_d; auto __v8 = (d::__ci(), new d()); return (__a7 = __v8); }());
   ([&]() -> decltype(auto) { auto& __a9 = this->d_d; auto __v10 = (d::__ci(), new d()); return (__a9 = __v10); }());
   ([&]() -> decltype(auto) { auto& __a11 = this->e_d; auto __v12 = (d::__ci(), new d()); return (__a11 = __v12); }());
}
int8_t j::a__b() {
   return this->c_b;
}
void j::d__v() {
   if (this->e_z) {
      if ((this->c_j != nullptr)) {
         (d::__ci(), d::a_ddd_v(this->c_j->b_d, this->c_d, this->b_d));
      } else {
         this->b_d->a_d_v(this->c_d);
      }
      this->b_d->c_d_v(this->d_d);
      (this->e_z = false);
   }
}
void j::h__v() {
   for (j* L_var1 = this; (L_var1 != nullptr); (L_var1 = L_var1->a_j_j(this))) {
      {
         (L_var1->e_z = true);
         (L_var1->f_z = true);
         (L_var1->g_z = true);
      }
   }
}
void j::i__v() {
   for (j* L_var1 = this; (L_var1 != nullptr); (L_var1 = L_var1->c_j)) {
      {
         (L_var1->a_z = true);
      }
   }
}
void j::a_j_v(j* L_var1) {
}
void j::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
}
void j::b_j_v(j* L_var1) {
   if (L_var1->a_j_z(this)) {
      jthrow(JIllegalArgumentException::make());
   } else {
      if ((L_var1 == this)) {
         jthrow(JIllegalArgumentException::make());
      } else {
         this->j__v();
         (this->e_j = L_var1->d_j);
         if ((this->e_j != nullptr)) {
            (this->e_j->f_j = this);
         }
         (this->c_j = L_var1);
         (this->c_j->d_j = this);
      }
   }
}
void j::j__v() {
   if ((this->c_j != nullptr)) {
      if ((this->c_j->d_j == this)) {
         (this->c_j->d_j = this->e_j);
         if ((this->e_j != nullptr)) {
            (this->e_j->f_j = nullptr);
         }
      } else {
         if ((this->f_j != nullptr)) {
            (this->f_j->e_j = this->e_j);
         }
         if ((this->e_j != nullptr)) {
            (this->e_j->f_j = this->f_j);
         }
      }
      (this->c_j = nullptr);
      (this->e_j = nullptr);
      (this->f_j = nullptr);
   }
}
void j::a_d_v(d* L_var1) {
   if (this->f_z) {
      this->k__v();
   }
   L_var1->a_d_v(this->h_d);
}
void j::k__v() {
   this->h_d->a_d_v(this->c_d);
   for (j* L_var1 = this->c_j; (L_var1 != nullptr); (L_var1 = L_var1->c_j)) {
      {
         (d::__ci(), d::a_ddd_v(L_var1->c_d, this->h_d, this->h_d));
      }
   }
   this->h_d->c_d_v(this->e_d);
   (this->f_z = false);
}
bool j::a_j_z(j* L_var1) {
   for (j* L_var2 = this->c_j; (L_var2 != nullptr); (L_var2 = L_var2->c_j)) {
      {
         if ((L_var1 == L_var2)) {
            return true;
         }
      }
   }
   return false;
}
j* j::a_j_j(j* L_var1) {
   if ((L_var1 == nullptr)) {
      return static_cast<j*>(nullptr);
   } else {
      if ((this->d_j != nullptr)) {
         return this->d_j;
      } else {
         if ((this == L_var1)) {
            return static_cast<j*>(nullptr);
         } else {
            if ((this->e_j != nullptr)) {
               return this->e_j;
            } else {
               for (j* L_var2 = this->c_j; ((L_var2 != nullptr) && (L_var2 != L_var1)); (L_var2 = L_var2->c_j)) {
                  {
                     if ((L_var2->e_j != nullptr)) {
                        return L_var2->e_j;
                     }
                  }
               }
               return static_cast<j*>(nullptr);
            }
         }
      }
   }
}
j* j::b_j_j(j* L_var1) {
   if ((L_var1 == nullptr)) {
      return static_cast<j*>(nullptr);
   } else {
      if ((this == L_var1)) {
         return static_cast<j*>(nullptr);
      } else {
         if ((this->e_j != nullptr)) {
            return this->e_j;
         } else {
            for (j* L_var2 = this->c_j; ((L_var2 != nullptr) && (L_var2 != L_var1)); (L_var2 = L_var2->c_j)) {
               {
                  if ((L_var2->e_j != nullptr)) {
                     return L_var2->e_j;
                  }
               }
            }
            return static_cast<j*>(nullptr);
         }
      }
   }
}
int16_t j::a__s() {
   return this->c_s;
}
void j::a_s_v(int16_t L_var1) {
   (this->c_s = L_var1);
}
j* j::a_s_j(int16_t L_var1) {
   j* L_var2 = nullptr;
   (L_var2 = this);
   while (((L_var2 != nullptr) && (L_var2->c_s != L_var1))) {
      {
         (L_var2 = L_var2->a_j_j(this));
      }
   }
   return L_var2;
}
j* j::a__j() {
   j* L_var1 = this;
   while ((L_var1->c_j != nullptr)) {
      {
         (L_var1 = L_var1->c_j);
      }
   }
   return L_var1;
}
void j::a__v() {
   (this->e_i = J_Integer_MAX_VALUE);
   (this->f_i = J_Integer_MAX_VALUE);
   (this->g_i = J_Integer_MIN_VALUE);
   (this->h_i = J_Integer_MIN_VALUE);
}
void j::l__v() {
   if (this->a_z) {
      (this->i_i = this->e_i);
      (this->j_i = this->f_i);
      (this->k_i = this->g_i);
      (this->l_i = this->h_i);
      for (j* L_var1 = this->d_j; (L_var1 != nullptr); (L_var1 = L_var1->e_j)) {
         {
            L_var1->l__v();
            L_var1->c_d->a_ii_v(L_var1->i_i, L_var1->j_i);
            if (((d::__ci(),d::g_i) < this->i_i)) {
               (this->i_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) < this->j_i)) {
               (this->j_i = (d::__ci(),d::h_i));
            }
            if (((d::__ci(),d::g_i) > this->k_i)) {
               (this->k_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) > this->l_i)) {
               (this->l_i = (d::__ci(),d::h_i));
            }
            L_var1->c_d->a_ii_v(L_var1->i_i, L_var1->l_i);
            if (((d::__ci(),d::g_i) < this->i_i)) {
               (this->i_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) < this->j_i)) {
               (this->j_i = (d::__ci(),d::h_i));
            }
            if (((d::__ci(),d::g_i) > this->k_i)) {
               (this->k_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) > this->l_i)) {
               (this->l_i = (d::__ci(),d::h_i));
            }
            L_var1->c_d->a_ii_v(L_var1->k_i, L_var1->l_i);
            if (((d::__ci(),d::g_i) < this->i_i)) {
               (this->i_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) < this->j_i)) {
               (this->j_i = (d::__ci(),d::h_i));
            }
            if (((d::__ci(),d::g_i) > this->k_i)) {
               (this->k_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) > this->l_i)) {
               (this->l_i = (d::__ci(),d::h_i));
            }
            L_var1->c_d->a_ii_v(L_var1->k_i, L_var1->j_i);
            if (((d::__ci(),d::g_i) < this->i_i)) {
               (this->i_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) < this->j_i)) {
               (this->j_i = (d::__ci(),d::h_i));
            }
            if (((d::__ci(),d::g_i) > this->k_i)) {
               (this->k_i = (d::__ci(),d::g_i));
            }
            if (((d::__ci(),d::h_i) > this->l_i)) {
               (this->l_i = (d::__ci(),d::h_i));
            }
         }
      }
      (this->a_z = false);
   }
}
int32_t j::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   ([&]() -> decltype(auto) { auto& __a13 = this->a_s; auto __v14 = j::a_Abi_s(L_var1, L_var2); return (__a13 = __v14); }());
   (L_var2 += 2);
   ([&]() -> decltype(auto) { auto& __a15 = this->b_s; auto __v16 = j::a_Abi_s(L_var1, L_var2); return (__a15 = __v16); }());
   (L_var2 += 2);
   int32_t L_var3 = ((int32_t)(L_var1[L_var2]));
   (L_var2++);
   if ((((L_var3 & 7)) == 7)) {
      ([&]() -> decltype(auto) { auto& __a17 = this->c_d->a_i; auto __v18 = j::b_Abi_i(L_var1, L_var2); return (__a17 = __v18); }());
      (L_var2 += 4);
      ([&]() -> decltype(auto) { auto& __a19 = this->c_d->b_i; auto __v20 = j::b_Abi_i(L_var1, L_var2); return (__a19 = __v20); }());
      (L_var2 += 4);
      ([&]() -> decltype(auto) { auto& __a21 = this->c_d->c_i; auto __v22 = j::b_Abi_i(L_var1, L_var2); return (__a21 = __v22); }());
      (L_var2 += 4);
      ([&]() -> decltype(auto) { auto& __a23 = this->c_d->d_i; auto __v24 = j::b_Abi_i(L_var1, L_var2); return (__a23 = __v24); }());
      (L_var2 += 4);
      ([&]() -> decltype(auto) { auto& __a25 = this->c_d->e_i; auto __v26 = j::b_Abi_i(L_var1, L_var2); return (__a25 = __v26); }());
      (L_var2 += 4);
      ([&]() -> decltype(auto) { auto& __a27 = this->c_d->f_i; auto __v28 = j::b_Abi_i(L_var1, L_var2); return (__a27 = __v28); }());
      (L_var2 += 4);
   } else {
      if ((((L_var3 & 1)) > 0)) {
         ([&]() -> decltype(auto) { auto& __a29 = this->c_d->c_i; auto __v30 = jshl(int32_t(j::a_Abi_s(L_var1, L_var2)),16); return (__a29 = __v30); }());
         (L_var2 += 2);
         ([&]() -> decltype(auto) { auto& __a31 = this->c_d->f_i; auto __v32 = jshl(int32_t(j::a_Abi_s(L_var1, L_var2)),16); return (__a31 = __v32); }());
         (L_var2 += 2);
      }
      if ((((L_var3 & 2)) > 0)) {
         this->c_d->a_f_v((((float)(j::b_Abi_i(L_var1, L_var2))) / 65536.0f));
         (L_var2 += 4);
      }
      if ((((L_var3 & 4)) > 0)) {
         ([&]() -> decltype(auto) { auto& __a33 = this->c_d->a_i; auto __v34 = j::b_Abi_i(L_var1, L_var2); return (__a33 = __v34); }());
         (L_var2 += 4);
         ([&]() -> decltype(auto) { auto& __a35 = this->c_d->e_i; auto __v36 = j::b_Abi_i(L_var1, L_var2); return (__a35 = __v36); }());
         (L_var2 += 4);
      }
   }
   ([&]() -> decltype(auto) { auto& __a37 = this->m_i; auto __v38 = j::b_Abi_i(L_var1, L_var2); return (__a37 = __v38); }());
   (this->b_b = ((int8_t)((jwrap32(jwint(((this->m_i & 31))) - jwint(16))))));
   (this->b_d->a_i = this->c_d->a_i);
   (this->b_d->b_i = this->c_d->b_i);
   (this->b_d->c_i = this->c_d->c_i);
   (this->b_d->d_i = this->c_d->d_i);
   (this->b_d->e_i = this->c_d->e_i);
   (this->b_d->f_i = this->c_d->f_i);
   return jwrap32(jwint(L_var2) + jwint(4));
}
void j::a_Aj_v(Arr<j*> L_var0) {
   for (int32_t L_var1 = 0; (L_var1 < L_var0.length()); (L_var1++)) {
      {
         j* L_var2{};
         if ((((L_var2 = L_var0[L_var1]))->a_s > (-1))) {
            j* L_var3 = L_var0[L_var2->a_s];
            (L_var2->c_j = L_var3);
            if ((L_var3->d_j == nullptr)) {
               (L_var3->d_j = L_var2);
            }
         }
         if ((L_var2->b_s > (-1))) {
            j* L_var5 = L_var0[L_var2->b_s];
            (L_var2->f_j = L_var5);
            (L_var5->e_j = L_var2);
         }
      }
   }
   for (int32_t L_var4 = 0; (L_var4 < L_var0.length()); (L_var4++)) {
      {
         (L_var0[L_var4]->e_z = true);
         (L_var0[L_var4]->a_z = true);
         (L_var0[L_var4]->f_z = true);
         L_var0[L_var4]->k__v();
         L_var0[L_var4]->a_d_v(j::a_d);
         L_var0[L_var4]->b_d->a_d_v(j::a_d);
         L_var0[L_var4]->b_d->c_d_v(L_var0[L_var4]->d_d);
      }
   }
}
int16_t j::a_Abi_s(Arr<int8_t> L_var0, int32_t L_var1) {
   int32_t L_var2 = 0;
   return ((int16_t)((([&]() { auto __l39 = jshl(int32_t(((L_var2 = (0 | L_var0[L_var1])))),8); auto __r40 = (L_var0[jwrap32(jwint(L_var1) + jwint(1))] & 255); return (__l39 | __r40); }()))));
}
int32_t j::b_Abi_i(Arr<int8_t> L_var0, int32_t L_var1) {
   int64_t L_var2 = (int64_t)0LL;
   return ((int32_t)((([&]() { auto __l45 = jshl(int64_t((([&]() { auto __l43 = jshl(int64_t((([&]() { auto __l41 = jshl(int64_t(((L_var2 = ((int64_t)0LL | ((int64_t)(L_var0[L_var1])))))),8); auto __r42 = ((int64_t)(((L_var0[jwrap32(jwint(L_var1) + jwint(1))] & 0xFF)))); return (__l41 | __r42); }()))),8); auto __r44 = ((int64_t)(((L_var0[jwrap32(jwint(L_var1) + jwint(2))] & 0xFF)))); return (__l43 | __r44); }()))),8); auto __r46 = ((int64_t)(((L_var0[jwrap32(jwint(L_var1) + jwint(3))] & 0xFF)))); return (__l45 | __r46); }()))));
}
int32_t j::a_AiiiAbii_i(Arr<int32_t> L_var0, int32_t L_var1, int32_t L_var2, Arr<int8_t> L_var3, int32_t L_var4, int32_t L_var5) {
   int32_t L_var6 = 0;
   int32_t L_var7 = 0;
   int32_t L_var12 = L_var5;
   int32_t L_var8 = 0;
   int32_t L_var9 = jshl(int32_t(1),jwrap32(jwint(L_var5) - jwint(1)));
   int32_t L_var10 = jwrap32(jwint((jshl(int32_t(1),L_var5))) - jwint(1));
   while ((L_var8 < L_var1)) {
      {
         (L_var6 |= ([&]() { auto __l47 = L_var3[(L_var4++)]; auto __r48 = L_var7; return jshl(int32_t(__l47),__r48); }()));
         (L_var7 += 8);
         for ((L_var6 &= jwrap32(jwint((jshl(int32_t(1),L_var7))) - jwint(1))); (L_var7 >= L_var12); (L_var6 = jushr(int32_t(L_var6),L_var12))) {
            {
               int32_t L_var11{};
               if (((([&]() { auto __l49 = ((L_var11 = (L_var6 & L_var10))); auto __r50 = L_var9; return (__l49 & __r50); }())) > 0)) {
                  (L_var11 |= (~L_var10));
               }
               if ((L_var8 < L_var1)) {
                  ([&]() -> decltype(auto) { auto& __a51 = L_var0[(L_var8++)]; auto __v52 = jshl(int32_t(jwrap32(jwint(L_var11) + jwint(L_var2))),16); return (__a51 = __v52); }());
               }
               (L_var7 -= L_var12);
            }
         }
      }
   }
   return L_var4;
}
int32_t j::a_AsiiiAbii_i(Arr<int16_t> L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, Arr<int8_t> L_var4, int32_t L_var5, int32_t L_var6) {
   (L_var3 = 0);
   int32_t L_var7 = 0;
   int32_t L_var14 = L_var6;
   int32_t L_var8 = 0;
   int32_t L_var9 = jshl(int32_t(1),jwrap32(jwint(L_var6) - jwint(1)));
   int32_t L_var10 = jwrap32(jwint((jshl(int32_t(1),L_var6))) - jwint(1));
   while ((L_var8 < L_var1)) {
      {
         (L_var3 |= ([&]() { auto __l53 = L_var4[(L_var5++)]; auto __r54 = L_var7; return jshl(int32_t(__l53),__r54); }()));
         (L_var7 += 8);
         for ((L_var3 &= jwrap32(jwint((jshl(int32_t(1),L_var7))) - jwint(1))); (L_var7 >= L_var14); (L_var3 = jushr(int32_t(L_var3),L_var14))) {
            {
               int32_t L_var11{};
               if (((([&]() { auto __l55 = ((L_var11 = (L_var3 & L_var10))); auto __r56 = L_var9; return (__l55 & __r56); }())) > 0)) {
                  (L_var11 |= (~L_var10));
               }
               if ((L_var8 < L_var1)) {
                  ([&]() -> decltype(auto) { auto& __a57 = L_var0[(L_var8++)]; auto __v58 = ((int16_t)((jwrap32(jwint(L_var11) + jwint(L_var2))))); return (__a57 = __v58); }());
               }
               (L_var7 -= L_var14);
            }
         }
      }
   }
   return L_var5;
}
bool j::a_iiiiiiii_z(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7) {
   int64_t L_var8 = ((int64_t)((jwrap32(jwint(L_var6) - jwint(L_var4)))));
   int64_t L_var10 = ((int64_t)((jwrap32(jwint(L_var7) - jwint(L_var5)))));
   int64_t L_var12 = ((int64_t)((jwrap32(jwint(L_var2) - jwint(L_var0)))));
   int64_t L_var14 = ((int64_t)((jwrap32(jwint(L_var3) - jwint(L_var1)))));
   int64_t L_var16 = ((int64_t)((jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var0) + jwint(L_var2))) - jwint(L_var4))) - jwint(L_var6)))));
   int64_t L_var18 = ((int64_t)((jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var1) + jwint(L_var3))) - jwint(L_var5))) - jwint(L_var7)))));
   int64_t L_var20 = ((L_var12 > (int64_t)0LL) ? L_var12 : (-L_var12));
   if (((((L_var16 > (int64_t)0LL) ? L_var16 : (-L_var16))) > jwrap64(jwlong(L_var8) + jwlong(L_var20)))) {
      return false;
   } else {
      int64_t L_var22 = ((L_var14 > (int64_t)0LL) ? L_var14 : (-L_var14));
      int64_t L_var24{};
      return (((((L_var18 > (int64_t)0LL) ? L_var18 : (-L_var18))) > jwrap64(jwlong(L_var10) + jwlong(L_var22))) ? false : ([&]() { auto __l59 = (((((L_var24 = jwrap64(jwlong(jwrap64(jwlong(L_var16) * jwlong(L_var14))) - jwlong(jwrap64(jwlong(L_var18) * jwlong(L_var12)))))) > (int64_t)0LL) ? L_var24 : (-L_var24))); auto __r60 = jwrap64(jwlong(jwrap64(jwlong(L_var8) * jwlong(L_var22))) + jwlong(jwrap64(jwlong(L_var10) * jwlong(L_var20)))); return (__l59 <= __r60); }()));
   }
}
bool j::b_iiiiiiii_z(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7) {
   return (((L_var2 < L_var4) || (L_var0 > L_var6)) ? false : ((L_var3 >= L_var5) && (L_var1 <= L_var7)));
}
bool j::a_iiiiii_z(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5) {
   return (((L_var0 < L_var2) || (L_var0 > L_var4)) ? false : ((L_var1 >= L_var3) && (L_var1 <= L_var5)));
}
void j::m__v() {
   (j::n_i = 0);
   (j::o_i = 0);
   j::b_z_v(true);
}
void j::b_z_v(bool L_var0) {
   int32_t L_var1 = (o::__ci(),o::a_i);
   int32_t L_var2 = 0;
   int32_t L_var3 = 0;
   j::a_j->a_d_v(j::a_d);
   if ((L_var1 != 0)) {
      (L_var2 = jdiv(int32_t((jwrap32(jwint(j::a_d->c_i) - jwint(j::a_j->b_d->c_i)))),int32_t(L_var1)));
      (L_var3 = jdiv(int32_t((jwrap32(jwint(j::a_d->f_i) - jwint(j::a_j->b_d->f_i)))),int32_t(L_var1)));
   }
   (L_var2 = jshl(int32_t(L_var2),7));
   (L_var3 = jshl(int32_t((-L_var3)),7));
   int32_t L_var4 = j::a_d->c_i;
   int32_t L_var5 = j::a_d->f_i;
   int32_t L_var6 = jshl(int32_t(jdiv(int32_t((-(o::__ci(),o::c_i))),int32_t(5))),16);
   j::g_d->c_d_v((d::__ci(),d::a_d));
   (d::__ci(),d::a_d)->b_ii_v(0, L_var6);
   (L_var6 = (d::__ci(),d::g_i));
   int32_t L_var7 = (d::__ci(),d::h_i);
   (d::__ci(),d::a_d)->b_ii_v(L_var2, L_var3);
   (L_var2 = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var4) + jwint(L_var6))) + jwint(L_var2))) + jwint((d::__ci(),d::g_i))));
   (L_var3 = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var5) + jwint(L_var7))) + jwint(L_var3))) + jwint((d::__ci(),d::h_i))));
   if (L_var0) {
      (j::f_d->c_i = L_var2);
      (j::f_d->f_i = L_var3);
   } else {
      int32_t L_var8 = jwrap32(jwint(L_var2) - jwint(j::f_d->c_i));
      (L_var2 = jwrap32(jwint(L_var3) - jwint(j::f_d->f_i)));
      if ((jmath_abs<int32_t>(L_var8) < 327680)) {
         (L_var8 = 0);
      }
      if ((jmath_abs<int32_t>(L_var2) < 327680)) {
         (L_var2 = 0);
      }
      for ((j::a_i += L_var1); (j::a_i >= 15); (j::a_i -= 15)) {
         {
            (j::f_d->c_i = jwrap32(jwint(j::f_d->c_i) + jwint(jwrap32(jwint(j::n_i) * jwint(15)))));
            (j::f_d->f_i = jwrap32(jwint(j::f_d->f_i) + jwint(jwrap32(jwint(j::o_i) * jwint(15)))));
            (j::n_i = jwrap32(jwint(j::n_i) + jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(15) * jwint(j::p_i))) * jwint((jshr(int32_t(L_var8),6))))),14)))));
            (j::o_i = jwrap32(jwint(j::o_i) + jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(15) * jwint(j::p_i))) * jwint((jshr(int32_t(L_var2),6))))),14)))));
            (j::n_i = jwrap32(jwint(j::n_i) - jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(15) * jwint(j::q_i))) * jwint(j::n_i))),14)))));
            (j::o_i = jwrap32(jwint(j::o_i) - jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(15) * jwint(j::q_i))) * jwint(j::o_i))),14)))));
         }
      }
   }
}
void j::a_jGraphicsDirectGraphics_v(j* L_var0, JGraphics L_var1, JDirectGraphics L_var2) {
   j::f_d->c_d_v(j::i_d);
   (d::__ci(), d::a_ddd_v(j::g_d, j::i_d, j::j_d));
   (j::j_d->c_i = jshr(int32_t(j::j_d->c_i),16));
   (j::j_d->c_i = jshl(int32_t(j::j_d->c_i),16));
   (j::j_d->f_i = jshr(int32_t(j::j_d->f_i),16));
   (j::j_d->f_i = jshl(int32_t(j::j_d->f_i),16));
   j::j_d->c_d_v(j::k_d);
   (L_var0 = L_var0);
   j::k_d->a_ii_v(0, 0);
   int32_t L_var3 = (d::__ci(),d::g_i);
   int32_t L_var4 = (d::__ci(),d::h_i);
   j::k_d->a_ii_v(jshl(int32_t((o::__ci(),o::b_i)),16), jshl(int32_t((o::__ci(),o::c_i)),16));
   int32_t L_var5 = (d::__ci(),d::g_i);
   int32_t L_var6 = (d::__ci(),d::h_i);
   if ((L_var3 > L_var5)) {
      (L_var5 = L_var3);
      (L_var3 = (d::__ci(),d::g_i));
   }
   if ((L_var4 > L_var6)) {
      (L_var6 = L_var4);
      (L_var4 = (d::__ci(),d::h_i));
   }
   (j::b_i = 0);
   j* L_var7 = L_var0;
   while ((L_var7 != nullptr)) {
      {
         L_var7->a_d_v(j::a_d);
         j::a_d->a_ii_v(L_var7->i_i, L_var7->j_i);
         int32_t L_var8 = (d::__ci(),d::g_i);
         int32_t L_var9 = (d::__ci(),d::h_i);
         int32_t L_var10 = (d::__ci(),d::g_i);
         int32_t L_var11 = (d::__ci(),d::h_i);
         j::a_d->a_ii_v(L_var7->i_i, L_var7->l_i);
         if (((d::__ci(),d::g_i) < L_var8)) {
            (L_var8 = (d::__ci(),d::g_i));
         }
         if (((d::__ci(),d::h_i) < L_var9)) {
            (L_var9 = (d::__ci(),d::h_i));
         }
         if (((d::__ci(),d::g_i) > L_var10)) {
            (L_var10 = (d::__ci(),d::g_i));
         }
         if (((d::__ci(),d::h_i) > L_var11)) {
            (L_var11 = (d::__ci(),d::h_i));
         }
         j::a_d->a_ii_v(L_var7->k_i, L_var7->l_i);
         if (((d::__ci(),d::g_i) < L_var8)) {
            (L_var8 = (d::__ci(),d::g_i));
         }
         if (((d::__ci(),d::h_i) < L_var9)) {
            (L_var9 = (d::__ci(),d::h_i));
         }
         if (((d::__ci(),d::g_i) > L_var10)) {
            (L_var10 = (d::__ci(),d::g_i));
         }
         if (((d::__ci(),d::h_i) > L_var11)) {
            (L_var11 = (d::__ci(),d::h_i));
         }
         j::a_d->a_ii_v(L_var7->k_i, L_var7->j_i);
         if (((d::__ci(),d::g_i) < L_var8)) {
            (L_var8 = (d::__ci(),d::g_i));
         }
         if (((d::__ci(),d::h_i) < L_var9)) {
            (L_var9 = (d::__ci(),d::h_i));
         }
         if (((d::__ci(),d::g_i) > L_var10)) {
            (L_var10 = (d::__ci(),d::g_i));
         }
         if (((d::__ci(),d::h_i) > L_var11)) {
            (L_var11 = (d::__ci(),d::h_i));
         }
         bool L_var12{};
         if (((!((L_var12 = (L_var7->c_b == 11)))) && (!j::b_iiiiiiii_z(L_var8, L_var9, L_var10, L_var11, L_var3, L_var4, L_var5, L_var6)))) {
            (L_var7 = L_var7->b_j_j(L_var0));
         } else {
            if ((((L_var7->m_i & 128)) > 0)) {
               (L_var7 = L_var7->a_j_j(L_var0));
            } else {
               (j::a_Aj[j::b_i] = L_var7);
               (j::b_i++);
               (L_var7 = L_var7->a_j_j(L_var0));
            }
         }
      }
   }
   (L_var3 = j::b_i);
   Arr<j*> L_var14 = j::a_Aj;
   if (((j::a_Aj != nullptr) && (L_var3 > 1))) {
      if ((L_var3 == 2)) {
         if ((L_var14[0]->b_b < L_var14[1]->b_b)) {
            j* L_var18 = L_var14[0];
            (L_var14[0] = L_var14[1]);
            (L_var14[1] = L_var18);
         }
      } else {
         j::a_Ajii_v(L_var14, 0, jwrap32(jwint(L_var3) - jwint(1)));
      }
   }
   for (int32_t L_var15 = 0; (L_var15 < j::b_i); (L_var15++)) {
      {
         j::a_Aj[L_var15]->a_GraphicsDirectGraphicsd_v(L_var1, L_var2, j::j_d);
      }
   }
   (j::b_i = 0);
   for (int32_t L_var16 = 0; (L_var16 < j::a_Aj.length()); (L_var16++)) {
      {
         (j::a_Aj[L_var16] = nullptr);
      }
   }
}
void j::a_Ajii_v(Arr<j*> L_var0, int32_t L_var1, int32_t L_var2) {
   if ((L_var1 < L_var2)) {
      int32_t L_var5 = L_var2;
      Arr<j*> L_var3 = L_var0;
      j* L_var6 = L_var0[L_var2];
      int32_t L_var7 = jwrap32(jwint(L_var1) - jwint(1));
      for (int32_t L_var4 = L_var1; (L_var4 < L_var5); (L_var4++)) {
         {
            if ((L_var6->b_b < L_var3[L_var4]->b_b)) {
               j* L_var8 = L_var3[(++L_var7)];
               (L_var3[L_var7] = L_var3[L_var4]);
               (L_var3[L_var4] = L_var8);
            }
         }
      }
      (L_var3[L_var5] = L_var3[jwrap32(jwint(L_var7) + jwint(1))]);
      (L_var3[jwrap32(jwint(L_var7) + jwint(1))] = L_var6);
      int32_t L_var9 = jwrap32(jwint(L_var7) + jwint(1));
      j::a_Ajii_v(L_var0, L_var1, jwrap32(jwint(L_var9) - jwint(1)));
      j::a_Ajii_v(L_var0, jwrap32(jwint(L_var9) + jwint(1)), L_var2);
   }
}
void a::__clinit() {
   __inited = true;
   j::__ci();
}
a::a() {
   (this->c_b = ((int8_t)(9)));
}
int32_t a::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   return j::a_Abi_i(L_var1, L_var2);
}
void a::a__v() {
   (this->e_i = (-2949120));
   (this->g_i = 2949120);
   (this->f_i = (-2949120));
   (this->h_i = 2949120);
}
void a::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   this->a_d_v(j::a_d);
   (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
   int32_t L_var4 = jshr(int32_t((d::__ci(),d::a_d)->c_i),16);
   int32_t L_var5 = jshr(int32_t((d::__ci(),d::a_d)->f_i),16);
   (o::__ci(), o::a_iii_v(L_var4, L_var5, 208));
}
void b::__clinit() {
   __inited = true;
   a_i = jushr(int32_t((o::__ci(),o::b_i)),5);
   Arr<char16_t> L_var10000 = Arr<char16_t>({char16_t(u'\n'), char16_t(u' '), char16_t(u'-')});
}
b::b(JString L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5) {
   this->h_i = 0;
   (this->e_i = L_var4);
   (this->a_String = L_var1);
   (this->f_i = L_var3);
   {
      switch ((this->e_i & 3)) {
      case 1:
      {
         (this->g_i = 2);
         break;
      }
      case 2:
      {
         (this->g_i = 3);
         break;
      }
      default:
      {
         (this->g_i = 1);
      }
      }
   }
   if ((L_var5 >= 0)) {
      (this->d_i = L_var5);
      ([&]() -> decltype(auto) { auto& __a63 = this->l_i; auto __v64 = ([&]() { auto __l61 = (o::__ci(), o::a_ii_i(L_var5, 0)); auto __r62 = b::a_i; return jwrap32(jwint(__l61) + jwint(__r62)); }()); return (__a63 = __v64); }());
      ([&]() -> decltype(auto) { auto& __a65 = this->k_i; auto __v66 = (o::__ci(), o::a_ii_i(L_var5, 1)); return (__a65 = __v66); }());
   } else {
      (this->d_i = (-1));
      (this->l_i = 0);
      (this->k_i = 0);
   }
   (this->a_z = (((L_var2 > this->l_i) && (((this->e_i & 128)) == 128)) && (((this->e_i & 48)) != 32)));
   bool L_var6 = false;
   if ((((this->e_i & 256)) == 256)) {
      (L_var6 = true);
   }
   (this->a_String = ((L_var1 != nullptr) ? L_var1 : JS(u"")));
   ([&]() -> decltype(auto) { auto& __a67 = this->a_AString; auto __v68 = (o::__ci(), o::a_Stringiiziiz_AString(this->a_String, L_var2, this->f_i, this->a_z, this->l_i, this->k_i, L_var6)); return (__a67 = __v68); }());
   this->a_String_v(this->a_AString[0]);
}
void b::a_String_v(JString L_var1) {
   Arr<int32_t> L_var2 = newArr<int32_t>(4);
   if ((L_var1 != nullptr)) {
      int32_t L_var3 = 0;
      for (int32_t L_var4 = 0; ([&]() { auto __l69 = L_var4; auto __r70 = L_var1.length(); return (__l69 < __r70); }()); (L_var4++)) {
         {
            if ((L_var1.charAt(L_var4) == char16_t(u' '))) {
               (L_var2[L_var3] = L_var4);
               (L_var3++);
            }
         }
      }
      try {
         ([&]() -> decltype(auto) { auto& __a71 = this->j_i; auto __v72 = JInteger::valueOf(L_var1.substring(0, L_var2[0])); return (__a71 = __v72); }());
      }
      catch (JException& L_var9) {
      }
      try {
         ([&]() -> decltype(auto) { auto& __a73 = this->h_i; auto __v74 = JInteger::valueOf(L_var1.substring(jwrap32(jwint(L_var2[0]) + jwint(1)), L_var2[1])); return (__a73 = __v74); }());
      }
      catch (JException& L_var8) {
         (this->h_i = 0);
      }
      try {
         ([&]() -> decltype(auto) { auto& __a75 = this->i_i; auto __v76 = JInteger::valueOf(L_var1.substring(jwrap32(jwint(L_var2[1]) + jwint(1)), L_var2[2])); return (__a75 = __v76); }());
      }
      catch (JException& L_var7) {
         (this->i_i = 0);
      }
      try {
         ([&]() -> decltype(auto) { auto& __a77 = this->b_i; auto __v78 = JInteger::valueOf(L_var1.substring(jwrap32(jwint(L_var2[2]) + jwint(1)), L_var2[3])); return (__a77 = __v78); }());
      }
      catch (JException& L_var6) {
         (this->b_i = 0);
      }
      try {
         ([&]() -> decltype(auto) { auto& __a81 = this->c_i; auto __v82 = JInteger::valueOf(([&]() -> decltype(auto) { auto __p79 = jwrap32(jwint(L_var2[3]) + jwint(1)); auto __p80 = L_var1.length(); return L_var1.substring(__p79, __p80); }())); return (__a81 = __v82); }());
      }
      catch (JNumberFormatException& L_var5) {
         (this->c_i = 0);
         return;
      }
   } else {
      (this->j_i = 0);
      (this->h_i = 0);
      (this->i_i = 0);
      (this->b_i = 0);
      (this->c_i = 0);
   }
}
void b::a_iiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4) {
   bool L_var11 = true;
   int32_t L_var5 = this->j_i;
   bool L_var12 = false;
   (L_var2 = L_var2);
   (L_var1 = L_var1);
   b* L_var13 = this;
   (o::__ci(), o::a_ii_v(this->f_i, this->g_i));
   (o::__ci(), o::b_ii_v(0, L_var3));
   (o::__ci(), o::b_ii_v(1, L_var4));
   if ((L_var5 > this->j_i)) {
      (L_var5 = this->j_i);
   }
   int32_t L_var18{};
   if ((((this->e_i & 48)) == 32)) {
      (L_var3 = jdiv(int32_t(this->b_i),int32_t(2)));
      (L_var18 = 17);
   } else {
      int32_t L_var6{};
      if ((((this->e_i & 12)) == 8)) {
         (L_var6 = jdiv(int32_t((jwrap32(jwint(this->b_i) - jwint(this->i_i)))),int32_t(2)));
      } else {
         (L_var6 = 0);
      }
      if ((((this->e_i & 48)) == 0)) {
         (L_var3 = L_var6);
         (L_var18 = 20);
      } else {
         (L_var3 = jwrap32(jwint(this->b_i) - jwint(L_var6)));
         (L_var18 = 24);
      }
   }
   bool L_var20 = (((this->e_i & 48)) == 0);
   int32_t L_var7 = 0;
   int32_t L_var8 = 0;
   int32_t L_var9 = 0;
   int32_t L_var10 = 0;
   {
      switch ((this->e_i & 12)) {
      case 0:
      {
         (L_var8 = 20);
         (L_var10 = 0);
         (L_var7 = 20);
         if (L_var20) {
            (L_var9 = this->l_i);
         } else {
            (L_var9 = 0);
         }
         break;
      }
      case 4:
      {
         (L_var8 = 24);
         (L_var10 = this->b_i);
         (L_var7 = 24);
         if (L_var20) {
            (L_var9 = this->b_i);
         } else {
            (L_var9 = jwrap32(jwint(this->b_i) - jwint(this->l_i)));
         }
         break;
      }
      case 8:
      {
         (L_var8 = 17);
         (L_var10 = jdiv(int32_t(this->b_i),int32_t(2)));
         if (L_var20) {
            (L_var7 = 20);
            (L_var9 = jwrap32(jwint(jdiv(int32_t((jwrap32(jwint(this->b_i) - jwint(this->i_i)))),int32_t(2))) + jwint(this->l_i)));
         } else {
            (L_var7 = 24);
            (L_var9 = jwrap32(jwint(jwrap32(jwint(this->b_i) - jwint(jdiv(int32_t((jwrap32(jwint(this->b_i) - jwint(this->i_i)))),int32_t(2))))) - jwint(this->l_i)));
         }
      }
      }
   }
   if ((this->d_i >= 0)) {
      (o::__ci(), o::a_iiii_v(jwrap32(jwint(L_var1) + jwint(L_var3)), L_var2, this->d_i, L_var18));
   }
   if ((!this->a_z)) {
      (L_var2 += this->k_i);
   }
   (L_var3 = jwrap32(jwint(0) * jwint((o::__ci(), o::a_i_i(this->f_i)))));
   for (int32_t L_var19 = 0; (L_var19 < L_var5); (L_var19++)) {
      {
         if ((L_var13->a_AString[jwrap32(jwint(L_var19) + jwint(1))] != nullptr)) {
            if ((L_var19 < L_var13->h_i)) {
               ([&]() -> decltype(auto) { auto __p83 = L_var13->a_AString[jwrap32(jwint(L_var19) + jwint(1))]; auto __p84 = 0; auto __p85 = L_var13->a_AString[jwrap32(jwint(L_var19) + jwint(1))].length(); auto __p86 = jwrap32(jwint(L_var1) + jwint(L_var9)); auto __p87 = jwrap32(jwint(L_var2) + jwint(L_var3)); auto __p88 = L_var7; return (o::__ci(), o::a_Stringiiiii_v(__p83, __p84, __p85, __p86, __p87, __p88)); }());
            } else {
               ([&]() -> decltype(auto) { auto __p89 = L_var13->a_AString[jwrap32(jwint(L_var19) + jwint(1))]; auto __p90 = 0; auto __p91 = L_var13->a_AString[jwrap32(jwint(L_var19) + jwint(1))].length(); auto __p92 = jwrap32(jwint(L_var1) + jwint(L_var10)); auto __p93 = jwrap32(jwint(L_var2) + jwint(L_var3)); auto __p94 = L_var8; return (o::__ci(), o::a_Stringiiiii_v(__p89, __p90, __p91, __p92, __p93, __p94)); }());
            }
            (L_var3 += (o::__ci(), o::a_i_i(L_var13->f_i)));
         }
      }
   }
}
void c::__clinit() {
   __inited = true;
   j::__ci();
   l_f = 0.0f;
   m_f = (-400.0f);
   b_Af = Arr<float>({0.6f, 0.3f, 0.6f});
   c_Af = Arr<float>({0.1f, 0.1f, 0.1f});
   d_Af = Arr<float>({((float)(std::cos(0.9599311f))), ((float)(std::cos(0.9599311f))), ((float)(std::cos(0.9599311f)))});
   a_Ai = Arr<int32_t>({20, 20, 20});
   a_Af = Arr<float>({1.0f, 1.4f, 0.5f});
   e_Af = Arr<float>({500.0f, 350.0f, 312.5f});
   f_Af = Arr<float>({280.0f, 350.0f, 150.0f});
   g_Af = Arr<float>({1.5f, 2.5f, 1.2f});
   h_Af = Arr<float>({288.0f, 255.0f, 162.5f});
   b_Ai = newArr<int32_t>(3);
   c_Ai = Arr<int32_t>({458, 460, 454, 452, 456});
   a_As = Arr<int16_t>({((int16_t)(211)), ((int16_t)(212)), ((int16_t)(223)), ((int16_t)(234)), ((int16_t)(237)), ((int16_t)(238)), ((int16_t)(239)), ((int16_t)(240)), ((int16_t)(241)), ((int16_t)(242)), ((int16_t)(213)), ((int16_t)(214)), ((int16_t)(215)), ((int16_t)(216)), ((int16_t)(217)), ((int16_t)(218)), ((int16_t)(219)), ((int16_t)(220)), ((int16_t)(221)), ((int16_t)(222)), ((int16_t)(224)), ((int16_t)(225)), ((int16_t)(226)), ((int16_t)(227)), ((int16_t)(228)), ((int16_t)(229)), ((int16_t)(230)), ((int16_t)(231)), ((int16_t)(232)), ((int16_t)(233)), ((int16_t)(235)), ((int16_t)(236))});
   p_Ai = Arr<int32_t>({15592941, 25788, 15592941, 14752000, 15592941, 15261445});
   s_f = 1.5258789E-5f;
   (c::b_Ai[0] = jwrap32(jwint(jdiv(int32_t(jwrap32(jwint(c::a_Ai[0]) * jwint(j::g_d->a_i))),int32_t(65536))) + jwint(1)));
   (c::b_Ai[1] = jwrap32(jwint(jdiv(int32_t(jwrap32(jwint(c::a_Ai[1]) * jwint(j::g_d->a_i))),int32_t(65536))) + jwint(1)));
   (c::b_Ai[2] = jwrap32(jwint(jdiv(int32_t(jwrap32(jwint(c::a_Ai[2]) * jwint(j::g_d->a_i))),int32_t(65536))) + jwint(1)));
}
c::c(bool L_var1) {
   this->a_i = 0;
   this->r_i = 0;
   this->a_z = true;
   this->b_z = true;
   this->c_z = false;
   this->j_Ai = newArr<int32_t>(16);
   this->k_Ai = newArr<int32_t>(16);
   this->l_Ai = newArr<int32_t>(16);
   this->m_Ai = newArr<int32_t>(16);
   this->n_Ai = newArr<int32_t>(16);
   this->o_Ai = newArr<int32_t>(16);
   this->a_Az = newArr<bool>(16);
   this->o_f = 0.5f;
   this->u_i = 15539236;
   this->v_i = 16777215;
   this->w_i = 11473152;
   this->d_i = 0;
   this->d_z = false;
   this->h_z = false;
   (this->c_b = ((int8_t)(4)));
   (this->h_z = L_var1);
   if (L_var1) {
      (this->d_Ai = newArr<int32_t>(4));
      (this->e_Ai = newArr<int32_t>(4));
      (this->f_Ai = newArr<int32_t>(4));
      (this->g_Ai = newArr<int32_t>(4));
      (this->h_Ai = newArr<int32_t>(4));
      (this->i_Ai = newArr<int32_t>(4));
      this->n__v();
   }
}
void c::n__v() {
   for (int32_t L_var1 = 0; (L_var1 < 4); (L_var1++)) {
      {
         (this->d_Ai[L_var1] = 0);
         (this->e_Ai[L_var1] = 0);
         (this->f_Ai[L_var1] = 0);
         (this->g_Ai[L_var1] = 0);
      }
   }
}
void c::b__v() {
   float L_var1 = 0.0f;
   if (((m::__ci(),m::d_z) && (this->d_i == 0))) {
      (L_var1 = 50.0f);
   }
   if (this->d_z) {
      if ((this->a_f > ((-c::f_Af[this->d_i]) - L_var1))) {
         (this->d_f = (this->d_f - ((c::e_Af[this->d_i] + L_var1))));
         return;
      }
   } else {
      if ((this->a_f > ((-c::f_Af[this->d_i]) - L_var1))) {
         (this->d_f = (this->d_f - (((c::e_Af[this->d_i] + L_var1)) / c::g_Af[this->d_i])));
      }
   }
}
void c::c__v() {
   float L_var1 = 0.0f;
   if (((m::__ci(),m::d_z) && (this->d_i == 0))) {
      (L_var1 = 50.0f);
   }
   if (this->d_z) {
      if ((this->a_f < (c::f_Af[this->d_i] + L_var1))) {
         (this->d_f = ((this->d_f + c::e_Af[this->d_i]) + L_var1));
         return;
      }
   } else {
      if ((this->a_f < (c::f_Af[this->d_i] + L_var1))) {
         (this->d_f = (this->d_f + (((c::e_Af[this->d_i] + L_var1)) / c::g_Af[this->d_i])));
      }
   }
}
void c::a_z_v(bool L_var1) {
   if (((this->r_f > c::d_Af[this->d_i]) && this->d_z)) {
      if (L_var1) {
         (this->g_f = (this->g_f + (c::h_Af[this->d_i] / 2.0f)));
      } else {
         (this->g_f = (this->g_f + c::h_Af[this->d_i]));
      }
      (this->d_z = false);
      if (this->h_z) {
         if (L_var1) {
            this->b_ii_v(0, (-27));
            this->b_ii_v(1, (-27));
            return;
         }
         this->b_ii_v(0, (-53));
         this->b_ii_v(1, (-53));
      }
   }
}
void c::b_ii_v(int32_t L_var1, int32_t L_var2) {
   if ((L_var2 > 0)) {
      if ((L_var2 > 70)) {
         (L_var2 = 70);
      }
   } else {
      if (((L_var2 < 0) && (L_var2 < (-70)))) {
         (L_var2 = (-70));
      }
   }
   (this->d_Ai[L_var1] = jwrap32(jwint(this->d_Ai[L_var1]) + jwint(L_var2)));
}
void c::a__v() {
   (this->e_i = jshl(int32_t((-c::a_Ai[this->d_i])),16));
   (this->g_i = jshl(int32_t(c::a_Ai[this->d_i]),16));
   (this->f_i = jshl(int32_t((-c::a_Ai[this->d_i])),16));
   (this->h_i = jshl(int32_t(c::a_Ai[this->d_i]),16));
}
void c::d__v() {
   this->h__v();
   j::d__v();
   (this->f_z = true);
   if (this->a_z) {
      (this->d_f = (this->d_f + (0.0f * c::a_Af[this->d_i])));
      (this->e_f = (this->e_f + (c::m_f * c::a_Af[this->d_i])));
      if (this->h_z) {
         if ((!this->c_z)) {
            float L_var1 = (this->a_f - this->h_f);
            float L_var2 = (this->b_f - this->i_f);
            if ((L_var1 > 0.0f)) {
               this->b_ii_v(3, jdiv(int32_t((jshl(int32_t(jshr(int32_t(jf2i(L_var1)),2)),1))),int32_t(3)));
            } else {
               this->b_ii_v(2, jdiv(int32_t((jshl(int32_t(jshr(int32_t((-(jf2i(L_var1)))),2)),1))),int32_t(3)));
            }
            if ((L_var2 > 0.0f)) {
               this->b_ii_v(1, jdiv(int32_t((jshl(int32_t(jshr(int32_t(jf2i(L_var2)),2)),1))),int32_t(3)));
            } else {
               this->b_ii_v(0, jdiv(int32_t((jshl(int32_t(jshr(int32_t((-(jf2i(L_var2)))),2)),1))),int32_t(3)));
            }
         }
         (this->c_z = false);
      }
      float L_var11 = (((float)((o::__ci(),o::a_i))) * 0.001f);
      if (this->h_z) {
         (this->h_f = this->a_f);
         (this->i_f = this->b_f);
      }
      float L_var3 = (1.0f / c::a_Af[this->d_i]);
      (this->a_f = (this->a_f + ((this->d_f * L_var3) * L_var11)));
      (this->b_f = (this->b_f + ((this->e_f * L_var3) * L_var11)));
      (this->a_f = (this->a_f + (this->f_f * L_var3)));
      (this->b_f = (this->b_f + (this->g_f * L_var3)));
      (this->c_d->c_i = jwrap32(jwint(this->c_d->c_i) + jwint(jf2i((((this->a_f * L_var11) * 65536.0f))))));
      (this->c_d->f_i = jwrap32(jwint(this->c_d->f_i) + jwint(jf2i((((this->b_f * L_var11) * 65536.0f))))));
      (this->d_f = 0.0f);
      (this->e_f = 0.0f);
      (this->f_f = 0.0f);
      (this->g_f = 0.0f);
      float L_var4 = ([&]() { auto __l95 = ((L_var3 = ((this->j_f * this->q_f) + (this->k_f * this->r_f)))); auto __r96 = this->q_f; return (__l95 * __r96); }());
      (L_var3 *= this->r_f);
      if ((((this->q_f * this->j_f) + (this->r_f * this->k_f)) >= 0.0f)) {
         (L_var4 = (this->j_f - L_var4));
         (L_var3 = (this->k_f - L_var3));
      } else {
         (L_var4 = (this->j_f + L_var4));
         (L_var3 = (this->k_f + L_var3));
      }
      (L_var11 = ([&]() { auto __l99 = ([&]() { auto __l97 = ((float)(std::sqrt(((double)((((L_var4 * L_var4) + (L_var3 * L_var3)))))))); auto __r98 = ((float)(c::a_Ai[this->d_i])); return (__l97 / __r98); }()); auto __r100 = L_var11; return (__l99 * __r100); }()));
      if ((((this->q_f * L_var3) - (L_var4 * this->r_f)) > 0.0f)) {
         (L_var11 = (-L_var11));
      }
      (this->n_f += L_var11);
      (this->p_f = (this->p_f + (((float)((o::__ci(),o::a_i))) / 1000.0f)));
      if ((this->p_f > 0.25f)) {
         (this->d_z = false);
      }
      ([&]() -> decltype(auto) { auto& __a101 = this->c_f; auto __v102 = ((float)(std::sqrt(((double)((((this->a_f * this->a_f) + (this->b_f * this->b_f)))))))); return (__a101 = __v102); }());
      if ((this->c_f > 999.0f)) {
         float L_var6 = (999.0f / this->c_f);
         (this->a_f *= L_var6);
         (this->b_f *= L_var6);
         (this->c_f = 999.0f);
      }
      if (this->h_z) {
         for (int32_t L_var7 = 0; (L_var7 < 4); (L_var7++)) {
            {
               (this->g_Ai[L_var7] = jwrap32(jwint(this->g_Ai[L_var7]) + jwint(this->d_Ai[L_var7])));
               (this->d_Ai[L_var7] = 0);
               if ((this->g_Ai[L_var7] > 70)) {
                  (this->g_Ai[L_var7] = 70);
               } else {
                  if ((this->g_Ai[L_var7] < (-70))) {
                     (this->g_Ai[L_var7] = (-70));
                  }
               }
               (this->e_Ai[L_var7] = jwrap32(jwint(this->e_Ai[L_var7]) + jwint(jwrap32(jwint(this->g_Ai[L_var7]) * jwint((o::__ci(),o::a_i))))));
               (this->f_Ai[L_var7] = jdiv(int32_t(jwrap32(jwint(this->e_Ai[L_var7]) * jwint(j::g_d->a_i))),int32_t(65536)));
               (this->g_Ai[L_var7] = jwrap32(jwint(this->g_Ai[L_var7]) + jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint((o::__ci(),o::a_i)) * jwint(7))) * jwint((-this->e_Ai[L_var7])))),16)))));
               (this->g_Ai[L_var7] = jwrap32(jwint(this->g_Ai[L_var7]) - jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint((o::__ci(),o::a_i)) * jwint(120))) * jwint(this->g_Ai[L_var7]))),16)))));
            }
         }
      }
      if (this->h_z) {
         float L_var8 = 40.0f;
         if ((c::s_i > 0)) {
            (c::s_i = jwrap32(jwint(c::s_i) - jwint((o::__ci(),o::a_i))));
            (c::b_i = 3000);
            if ((c::s_i <= 0)) {
               if (((c::c_i >= 2) && (c::c_i <= 8))) {
                  int32_t L_var13{};
                  if ((jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(3))) == 0)) {
                     (L_var13 = 3);
                  } else {
                     (L_var13 = jwrap32(jwint(jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(6)))) + jwint(3)));
                  }
                  (c::s_i = 1500);
                  (c::c_i = L_var13);
                  if ((L_var13 == 3)) {
                     (c::s_i = 600);
                  }
               } else {
                  (c::s_i = 0);
                  (c::c_i = 0);
               }
            }
         } else {
            if (((((((g::__ci(),g::a_Ai)[0] == 0) && ((g::__ci(),g::a_Ai)[1] == 0)) && ([&]() { auto __l103 = jmath_abs<float>(this->a_f); auto __r104 = L_var8; return (__l103 < __r104); }())) && ([&]() { auto __l105 = jmath_abs<float>(this->b_f); auto __r106 = L_var8; return (__l105 < __r106); }())) && (((c::b_i = jwrap32(jwint(c::b_i) - jwint((o::__ci(),o::a_i))))) <= 0))) {
               (c::s_i = 600);
               (c::c_i = 2);
               (c::b_i = 3000);
            }
         }
         if ((([&]() { auto __l107 = jmath_abs<float>(this->a_f); auto __r108 = L_var8; return (__l107 >= __r108); }()) || ([&]() { auto __l109 = jmath_abs<float>(this->b_f); auto __r110 = L_var8; return (__l109 >= __r110); }()))) {
            if ((c::c_i != 1)) {
               (c::c_i = 0);
            }
            (c::b_i = 3000);
         }
      }
      if ((this->a_i != 0)) {
         int32_t L_var9 = jushr(int32_t(this->a_i),24);
         int32_t L_var14{};
         if ((((L_var14 = jdiv(int32_t((o::__ci(),o::a_i)),int32_t(2)))) < 1)) {
            (L_var14 = 1);
         }
         if ((((L_var9 = jwrap32(jwint(L_var9) - jwint(L_var14)))) < 0)) {
            (L_var9 = 0);
         }
         (this->a_i = jshl(int32_t(L_var9),24));
      }
   }
}
void c::a_ii_v(int32_t L_var1, int32_t L_var2) {
   this->g__v();
   (this->c_d->c_i = L_var1);
   (this->c_d->f_i = L_var2);
   (this->b_d->c_i = L_var1);
   (this->b_d->f_i = L_var2);
   (this->c_z = true);
   if (this->h_z) {
      (this->h_f = 0.0f);
      (this->i_f = 0.0f);
      for (int32_t L_var3 = 0; (L_var3 < 4); (L_var3++)) {
         {
            (this->d_Ai[L_var3] = 0);
            (this->e_Ai[L_var3] = 0);
            (this->f_Ai[L_var3] = 0);
            (this->g_Ai[L_var3] = 0);
         }
      }
   }
   (this->f_z = true);
}
void c::a_j_v(j* L_var1) {
   int32_t L_var2 = 1;
   while (((++L_var2) < 10)) {
      {
         j* L_var4 = L_var1;
         c* L_var3 = this;
         (this->t_i = 0);
         int32_t L_var5 = jshl(int32_t(c::a_Ai[this->d_i]),16);
         int32_t L_var6 = jshl(int32_t(jwrap32(jwint(c::a_Ai[this->d_i]) * jwint(c::a_Ai[this->d_i]))),16);
         int32_t L_var7 = jwrap32(jwint(this->c_d->c_i) - jwint(this->b_d->c_i));
         int32_t L_var8 = jwrap32(jwint(this->c_d->f_i) - jwint(this->b_d->f_i));
         j* L_var9 = L_var1;
         while ((L_var9 != nullptr)) {
            {
               L_var9->d_d->a_ii_v(L_var3->b_d->c_i, L_var3->b_d->f_i);
               int32_t L_var10 = (d::__ci(),d::g_i);
               int32_t L_var11 = (d::__ci(),d::h_i);
               if (L_var9->f_z) {
                  L_var9->k__v();
               }
               L_var9->e_d->a_ii_v(L_var3->c_d->c_i, L_var3->c_d->f_i);
               int32_t L_var12 = (d::__ci(),d::g_i);
               int32_t L_var13 = (d::__ci(),d::h_i);
               int32_t L_var14 = L_var10;
               int32_t L_var15 = L_var12;
               if ((L_var10 > L_var12)) {
                  (L_var14 = L_var12);
                  (L_var15 = L_var10);
               }
               int32_t L_var16 = L_var11;
               int32_t L_var17 = L_var13;
               if ((L_var11 > L_var13)) {
                  (L_var16 = L_var13);
                  (L_var17 = L_var11);
               }
               (L_var14 -= L_var5);
               (L_var16 -= L_var5);
               (L_var15 += L_var5);
               (L_var17 += L_var5);
               if ((!j::b_iiiiiiii_z(L_var9->i_i, L_var9->j_i, L_var9->k_i, L_var9->l_i, L_var14, L_var16, L_var15, L_var17))) {
                  (L_var9 = L_var9->b_j_j(L_var4));
               } else {
                  if ((((L_var9->m_i & 32)) > 0)) {
                     (L_var9 = L_var9->a_j_j(L_var4));
                  } else {
                     {
                        p* L_var84{};
                        bool L_var93{};
                        int32_t L_var98{};
                        int32_t L_var100{};
                        int32_t L_var102{};
                        int32_t L_var104{};
                        int32_t L_var24{};
                        int32_t L_var25{};
                        int32_t L_var26{};
                        i* L_var83{};
                        int32_t L_var92{};
                        int32_t L_var97{};
                        k* L_var82{};
                        e* L_var81{};
                        int32_t L_var91{};
                        int32_t L_var96{};
                        a* L_var80{};
                        j* L_var90{};
                        int32_t L_var95{};
                        int32_t L_var21{};
                        l* L_var18{};
                        j* L_var19{};
                        bool L_var20{};
                        switch (L_var9->a__b()) {
                        case 2:
                        {
                           L_var84 = jdown<p>(L_var9);
                           L_var93 = false;
                           L_var98 = 0;
                           L_var100 = 0;
                           L_var102 = 0;
                           L_var104 = 0;
                           L_var24 = 0;
                           L_var25 = jwrap32(jwint(L_var84->a_i) - jwint(1));
                           L_var26 = 0;
                           for (; (L_var26 < L_var25); (L_var26++)) {
                              {
                                 int32_t L_var27 = L_var84->c_Ai[L_var26];
                                 int32_t L_var28 = L_var84->d_Ai[L_var26];
                                 int32_t L_var29 = L_var84->c_Ai[jwrap32(jwint(L_var26) + jwint(1))];
                                 int32_t L_var30 = L_var84->d_Ai[jwrap32(jwint(L_var26) + jwint(1))];
                                 int32_t L_var31 = L_var27;
                                 int32_t L_var32 = L_var29;
                                 if ((L_var27 > L_var29)) {
                                    (L_var31 = L_var29);
                                    (L_var32 = L_var27);
                                 }
                                 int32_t L_var33 = L_var28;
                                 int32_t L_var34 = L_var30;
                                 if ((L_var28 > L_var30)) {
                                    (L_var33 = L_var30);
                                    (L_var34 = L_var28);
                                 }
                                 if (j::b_iiiiiiii_z(L_var31, L_var33, L_var32, L_var34, L_var14, L_var16, L_var15, L_var17)) {
                                    if ((!L_var93)) {
                                       (L_var93 = true);
                                       (L_var98 = jwrap32(jwint(L_var12) - jwint(L_var10)));
                                       (L_var100 = jwrap32(jwint(L_var13) - jwint(L_var11)));
                                       if ((((L_var102 = jf2i(std::sqrt(((double)((jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var98))) * jwlong(((int64_t)(L_var98))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var100))) * jwlong(((int64_t)(L_var100))))))))))))) != 0)) {
                                          (L_var104 = ((int32_t)((jdiv(int64_t((jshl(int64_t(((int64_t)(L_var98))),16))),int64_t(((int64_t)(L_var102))))))));
                                          (L_var24 = ((int32_t)((jdiv(int64_t((jshl(int64_t(((int64_t)(L_var100))),16))),int64_t(((int64_t)(L_var102))))))));
                                       }
                                    }
                                    (L_var31 = jwrap32(jwint(L_var28) - jwint(L_var30)));
                                    (L_var32 = (-(jwrap32(jwint(L_var27) - jwint(L_var29)))));
                                    int32_t L_var35 = jf2i(std::sqrt(((double)((jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var31))) * jwlong(((int64_t)(L_var31))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var32))) * jwlong(((int64_t)(L_var32)))))))))));
                                    int32_t L_var36 = ((int32_t)((jdiv(int64_t((jshl(int64_t(jwrap64(jwlong(((int64_t)(L_var31))) * jwlong(((int64_t)(c::a_Ai[L_var3->d_i]))))),16))),int64_t(((int64_t)(L_var35)))))));
                                    (L_var35 = ((int32_t)((jdiv(int64_t((jshl(int64_t(jwrap64(jwlong(((int64_t)(L_var32))) * jwlong(((int64_t)(c::a_Ai[L_var3->d_i]))))),16))),int64_t(((int64_t)(L_var35))))))));
                                    int32_t L_var37 = jwrap32(jwint(L_var27) + jwint(L_var36));
                                    int32_t L_var38 = jwrap32(jwint(L_var28) + jwint(L_var35));
                                    (L_var36 = jwrap32(jwint(L_var29) + jwint(L_var36)));
                                    (L_var35 = jwrap32(jwint(L_var30) + jwint(L_var35)));
                                    if ((jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var98))) * jwlong(((int64_t)(L_var31))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var100))) * jwlong(((int64_t)(L_var32)))))) < (int64_t)0LL)) {
                                       if (c::a_iiiiiiiii_z(L_var10, L_var11, L_var98, L_var100, L_var37, L_var38, L_var36, L_var35, L_var6)) {
                                          L_var3->a_piiiiiz_v(L_var84, c::z_i, L_var7, L_var8, L_var31, L_var32, c::i_z);
                                       }
                                       if (c::c_iiiiiiii_z(L_var10, L_var11, L_var104, L_var24, L_var102, L_var27, L_var28, c::a_Ai[L_var3->d_i])) {
                                          (L_var31 = jwrap32(jwint(c::x_i) - jwint(L_var27)));
                                          (L_var32 = jwrap32(jwint(c::y_i) - jwint(L_var28)));
                                          L_var3->a_piiiiiz_v(L_var84, c::z_i, L_var7, L_var8, L_var31, L_var32, c::i_z);
                                       }
                                       if (c::c_iiiiiiii_z(L_var10, L_var11, L_var104, L_var24, L_var102, L_var29, L_var30, c::a_Ai[L_var3->d_i])) {
                                          (L_var31 = jwrap32(jwint(c::x_i) - jwint(L_var29)));
                                          (L_var32 = jwrap32(jwint(c::y_i) - jwint(L_var30)));
                                          L_var3->a_piiiiiz_v(L_var84, c::z_i, L_var7, L_var8, L_var31, L_var32, c::i_z);
                                       }
                                    }
                                 }
                              }
                           }
                           (L_var9 = L_var9->a_j_j(L_var4));
                           break;
                        }
                        case 3:
                        case 5:
                        default:
                        {
                           (L_var9 = L_var9->a_j_j(L_var4));
                           break;
                        }
                        case 4:
                        {
                           (L_var9 = L_var9->a_j_j(L_var4));
                           break;
                        }
                        case 6:
                        {
                           L_var92 = jshl(int32_t(((L_var83 = jdown<i>(L_var9)))->a_s),16);
                           L_var97 = jshl(int32_t(L_var83->c_s),16);
                           if (c::a_iiiiiiiii_z(L_var92, L_var97, jwrap32(jwint((jshl(int32_t(L_var83->b_s),16))) - jwint(L_var92)), 0, L_var10, L_var11, L_var12, L_var13, 0)) {
                              L_var83->a_ific_v(c::z_i, L_var3->b_f, c::a_Ai[L_var3->d_i], L_var3);
                           }
                           if ((jwrap32(jwint(L_var13) - jwint(L_var5)) < L_var83->b_i)) {
                              L_var83->a_iic_v(L_var12, jwrap32(jwint(L_var13) - jwint(L_var5)), L_var3);
                           }
                           (L_var9 = L_var9->a_j_j(L_var4));
                           break;
                        }
                        case 7:
                        {
                           L_var82 = jdown<k>(L_var9);
                           if (j::a_iiiiiiii_z(L_var10, L_var11, L_var12, L_var13, L_var82->a_i, L_var82->c_i, L_var82->b_i, L_var82->d_i)) {
                              L_var82->b__v();
                           }
                           (L_var9 = L_var9->a_j_j(L_var4));
                           break;
                        }
                        case 8:
                        {
                           L_var81 = jdown<e>(L_var9);
                           L_var91 = (-4587520);
                           L_var96 = 6225920;
                           if (c::a_iiiiiiiii_z(L_var91, L_var96, 9175040, 0, L_var10, L_var11, L_var12, L_var13, 0)) {
                              float L_var61 = L_var3->b_f;
                              if ((L_var61 < 0.0f)) {
                                 if ((((L_var13 = (-(jf2i(L_var61))))) < 100)) {
                                    (L_var13 = 100);
                                 }
                                 if ((L_var13 > 1000)) {
                                    (L_var13 = 1000);
                                 }
                                 (L_var81->b_i = jwrap32(jwint((jshr(int32_t(jwrap32(jwint(1100) - jwint(L_var13))),1))) + jwint(20)));
                                 (L_var81->a_i = ([&]() { auto __l111 = L_var81->b_i; auto __r112 = (o::__ci(), o::b_i_i(((int32_t)(L_var81->a_s)))); return jdiv(int32_t(__l111),int32_t(__r112)); }()));
                                 (L_var81->a_c = L_var3);
                                 (L_var81->a_f = ((((-L_var61) * ((float)(L_var81->a_b))) * 2.0f) / 100.0f));
                                 float L_var62 = (((400.0f * ((float)(L_var81->a_b))) * 2.0f) / 100.0f);
                                 if ((L_var81->a_f > L_var62)) {
                                    (L_var81->a_f = L_var62);
                                 }
                                 (L_var81->a_c->a_z = false);
                                 (L_var81->a_c->a_f = 0.0f);
                                 (L_var81->a_c->b_f = 0.0f);
                                 (L_var81->a_z = false);
                                 L_var81->b__v();
                                 if (L_var81->a_c->equals((m::__ci(),m::a_c))) {
                                    ((g::__ci(),g::a_Ai)[1] = 2);
                                 }
                              }
                           }
                           (L_var9 = L_var9->a_j_j(L_var4));
                           break;
                        }
                        case 9:
                        {
                           L_var80 = jdown<a>(L_var9);
                           L_var90 = L_var9->a_j_j(L_var4);
                           L_var95 = jshr(int32_t(L_var12),16);
                           L_var21 = jshr(int32_t(L_var13),16);
                           if ((jwrap32(jwint(jwrap32(jwint(L_var95) * jwint(L_var95))) + jwint(jwrap32(jwint(L_var21) * jwint(L_var21)))) < 2025)) {
                              L_var80->a_d_v(j::a_d);
                              (L_var11 = j::a_d->c_i);
                              (L_var12 = j::a_d->f_i);
                              (m::__ci(),m::f_n)->a_iiiiiii_v(8, L_var11, L_var12, 540, 0, 540, 0);
                              if (L_var80->equals((m::__ci(),m::a_a))) {
                                 ((m::__ci(),m::g_i)++);
                                 (L_var80->c_d->c_i = J_Integer_MAX_VALUE);
                                 (L_var80->c_d->f_i = J_Integer_MAX_VALUE);
                                 L_var80->b_d->a_d_v(L_var80->c_d);
                                 L_var80->b_d->c_d_v(L_var80->d_d);
                                 (L_var80->f_z = true);
                              } else {
                                 L_var80->j__v();
                                 ((m::__ci(),m::g_i)++);
                              }
                           }
                           (L_var9 = L_var90);
                           break;
                        }
                        case 10:
                        {
                           L_var18 = jdown<l>(L_var9);
                           L_var19 = L_var9->a_j_j(L_var4);
                           L_var20 = false;
                           if (((L_var18->a_b == 0) || ((L_var18->a_b == 2) && (((L_var18->d_b == 1) || L_var18->a_z))))) {
                              (L_var20 = j::a_iiiiiiii_z(L_var10, L_var11, L_var12, L_var13, L_var18->e_i, jwrap32(jwint(L_var18->f_i) + jwint(jdiv(int32_t((jshl(int32_t(jwrap32(jwint(L_var18->h_i) - jwint(L_var18->f_i))),1))),int32_t(3)))), L_var18->g_i, L_var18->h_i));
                           }
                           if (L_var20) {
                              L_var18->e__v();
                           } else {
                              if (j::a_iiiiiiii_z(L_var10, L_var11, L_var12, L_var13, L_var18->e_i, L_var18->f_i, L_var18->g_i, L_var18->h_i)) {
                                 L_var18->c__v();
                              }
                              if ((L_var18->a_b == 2)) {
                                 int32_t L_var22 = jdiv(int32_t(jwrap32(jwint(L_var18->a_i) * jwint(100))),int32_t(L_var18->b_i));
                                 int32_t L_var23 = jdiv(int32_t(jwrap32(jwint((jwrap32(jwint(L_var18->h_i) - jwint(L_var18->f_i)))) * jwint(L_var22))),int32_t(100));
                                 if (j::a_iiiiiiii_z(L_var10, L_var11, L_var12, L_var13, L_var18->e_i, L_var18->f_i, L_var18->g_i, jwrap32(jwint(L_var18->f_i) + jwint(L_var23)))) {
                                    L_var18->b__v();
                                 }
                              }
                           }
                           (L_var9 = L_var19);
                        }
                        }
                     }
                  }
               }
            }
         }
         if ((L_var3->t_i == 0)) {
            break;
         }
         (L_var3 = this);
         int64_t L_var52 = (int64_t)42949672960000LL;
         int64_t L_var53 = J_Long_MAX_VALUE;
         (L_var8 = (-1));
         for (int32_t L_var55 = 0; (L_var55 < L_var3->t_i); (L_var55++)) {
            {
               int64_t L_var58 = ((int64_t)((jwrap32(jwint(L_var3->j_Ai[L_var55]) - jwint(L_var3->b_d->c_i)))));
               int64_t L_var65 = ((int64_t)((jwrap32(jwint(L_var3->k_Ai[L_var55]) - jwint(L_var3->b_d->f_i)))));
               int64_t L_var71 = jwrap64(jwlong(jwrap64(jwlong(L_var58) * jwlong(L_var58))) + jwlong(jwrap64(jwlong(L_var65) * jwlong(L_var65))));
               if (L_var3->a_Az[L_var55]) {
                  (L_var71 = (-L_var71));
               }
               if ((L_var71 > L_var52)) {
                  J_System_out->println(jcat(JS(u"Sanity check failed! Found collision is too far, distance: "),(std::sqrt(((double)(L_var71))) / 65536.0)));
               } else {
                  if ((L_var71 < L_var53)) {
                     (L_var53 = L_var71);
                     (L_var8 = L_var55);
                  }
               }
            }
         }
         if ((L_var8 != (-1))) {
            float L_var59 = (1000.0f / ((float)((o::__ci(),o::a_i))));
            float L_var63 = (((float)(L_var3->j_Ai[L_var8])) * c::s_f);
            float L_var66 = (((float)(L_var3->k_Ai[L_var8])) * c::s_f);
            float L_var68 = (((float)(L_var3->l_Ai[L_var8])) * c::s_f);
            float L_var72 = (((float)(L_var3->m_Ai[L_var8])) * c::s_f);
            float L_var75 = (1.0f / ((float)(std::sqrt(((double)((((L_var68 * L_var68) + (L_var72 * L_var72)))))))));
            (L_var68 *= L_var75);
            (L_var72 *= L_var75);
            float L_var77 = (((float)(L_var3->n_Ai[L_var8])) * c::s_f);
            float L_var79 = (((float)(L_var3->o_Ai[L_var8])) * c::s_f);
            float L_var85{};
            float L_var94 = ([&]() { auto __l113 = ((L_var85 = ((L_var77 * L_var68) + (L_var79 * L_var72)))); auto __r114 = L_var68; return (__l113 * __r114); }());
            float L_var99 = (L_var85 * L_var72);
            if ((((L_var68 * L_var77) + (L_var72 * L_var79)) < 0.0f)) {
               (L_var94 = (-L_var94));
               (L_var99 = (-L_var99));
            }
            float L_var101 = (L_var77 * L_var59);
            float L_var103 = (L_var79 * L_var59);
            float L_var105 = (((float)((jwrap32(jwint(L_var3->c_d->c_i) - jwint(L_var3->j_Ai[L_var8]))))) * c::s_f);
            float L_var106 = (((float)((jwrap32(jwint(L_var3->c_d->f_i) - jwint(L_var3->k_Ai[L_var8]))))) * c::s_f);
            float L_var107 = (L_var63 + L_var77);
            float L_var108 = (L_var66 + L_var79);
            float L_var109 = (L_var68 * 0.01f);
            float L_var110 = (L_var72 * 0.01f);
            float L_var111 = ([&]() { auto __l115 = ((L_var85 = ((L_var105 * L_var68) + (L_var106 * L_var72)))); auto __r116 = L_var68; return (__l115 * __r116); }());
            float L_var114 = (L_var85 * L_var72);
            float L_var120 = ((L_var105 - L_var111) - (L_var111 * c::c_Af[L_var3->d_i]));
            float L_var126 = ((L_var106 - L_var114) - (L_var114 * c::c_Af[L_var3->d_i]));
            float L_var129 = (((L_var63 + L_var120) + L_var94) + L_var109);
            float L_var130 = (((L_var66 + L_var126) + L_var99) + L_var110);
            (L_var111 = ([&]() { auto __l117 = ((L_var85 = ((L_var3->a_f * L_var68) + (L_var3->b_f * L_var72)))); auto __r118 = L_var68; return (__l117 * __r118); }()));
            (L_var114 = (L_var85 * L_var72));
            (L_var120 = ((L_var3->a_f - L_var111) - (L_var111 * c::c_Af[L_var3->d_i])));
            (L_var126 = ((L_var3->b_f - L_var114) - (L_var114 * c::c_Af[L_var3->d_i])));
            (L_var111 = ([&]() { auto __l119 = ((L_var85 = ((L_var101 * L_var68) + (L_var103 * L_var72)))); auto __r120 = L_var68; return (__l119 * __r120); }()));
            (L_var114 = (L_var85 * L_var72));
            (L_var3->a_f = (L_var111 + L_var120));
            (L_var3->b_f = (L_var114 + L_var126));
            (L_var120 = (L_var3->a_f - L_var101));
            (L_var126 = (L_var3->b_f - L_var103));
            float L_var133{};
            float L_var137 = ((((L_var133 = ((float)(std::sqrt(((double)((((L_var120 * L_var120) + (L_var126 * L_var126)))))))))) != 0.0f) ? (L_var120 / L_var133) : 0.0f);
            (L_var133 = ((L_var133 != 0.0f) ? (L_var126 / L_var133) : 0.0f));
            (L_var85 = (-(((L_var68 * 0.0f) + (L_var72 * c::m_f)))));
            float L_var56 = ((c::b_Af[L_var3->d_i] * c::a_Af[L_var3->d_i]) * L_var85);
            float L_var139 = (L_var137 * L_var56);
            float L_var140 = (L_var133 * L_var56);
            float L_var57 = (c::a_Af[L_var3->d_i] * L_var59);
            (L_var137 = (L_var120 * L_var57));
            (L_var133 = (L_var126 * L_var57));
            if ((((L_var137 * L_var137) + (L_var133 * L_var133)) < ((L_var139 * L_var139) + (L_var140 * L_var140)))) {
               (L_var3->d_f -= L_var137);
               (L_var3->e_f -= L_var133);
            } else {
               (L_var3->d_f -= L_var139);
               (L_var3->e_f -= L_var140);
            }
            (L_var3->j_f = ((L_var3->j_f * ((1.0f - L_var3->o_f))) + (L_var120 * L_var3->o_f)));
            (L_var3->k_f = ((L_var3->k_f * ((1.0f - L_var3->o_f))) + (L_var126 * L_var3->o_f)));
            (L_var3->p_f = 0.0f);
            (L_var3->d_z = true);
            (L_var3->q_f = L_var68);
            (L_var3->r_f = L_var72);
            (L_var3->b_d->c_i = jf2i(((L_var107 * 65536.0f))));
            (L_var3->b_d->f_i = jf2i(((L_var108 * 65536.0f))));
            (L_var3->c_d->c_i = jf2i(((L_var129 * 65536.0f))));
            (L_var3->c_d->f_i = jf2i(((L_var130 * 65536.0f))));
            L_var3->k__v();
            L_var3->b_d->c_d_v(L_var3->d_d);
            (L_var3->t_i = 0);
         }
      }
   }
   (this->p_f = (this->p_f + (((float)((o::__ci(),o::a_i))) / 1000.0f)));
   if ((this->p_f > 0.25f)) {
      (this->d_z = false);
   }
}
void c::a_piiiiiz_v(p* L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, bool L_var7) {
   if ((L_var2 > 0)) {
      (this->j_Ai[this->t_i] = jwrap32(jwint(this->b_d->c_i) + jwint(((int32_t)((jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var3))) * jwlong(((int64_t)(L_var2))))),16)))))));
      (this->k_Ai[this->t_i] = jwrap32(jwint(this->b_d->f_i) + jwint(((int32_t)((jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var4))) * jwlong(((int64_t)(L_var2))))),16)))))));
      (this->a_Az[this->t_i] = L_var7);
      L_var1->b_d->b_ii_v(L_var5, L_var6);
      (L_var3 = (d::__ci(),d::g_i));
      (L_var4 = (d::__ci(),d::h_i));
      L_var1->a_d_v(j::a_d);
      j::a_d->b_ii_v(L_var5, L_var6);
      (L_var5 = (d::__ci(),d::g_i));
      (L_var6 = (d::__ci(),d::h_i));
      (this->l_Ai[this->t_i] = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var3))) * jwlong(((int64_t)((jwrap32(jwint(65536) - jwint(L_var2)))))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var5))) * jwlong(((int64_t)(L_var2))))))),16)))));
      (this->m_Ai[this->t_i] = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var4))) * jwlong(((int64_t)((jwrap32(jwint(65536) - jwint(L_var2)))))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var6))) * jwlong(((int64_t)(L_var2))))))),16)))));
   } else {
      if ((L_var2 < 0)) {
         jthrow(JIllegalStateException::make(jcat(JS(u"t < 0, t: "),L_var2)));
      }
      L_var1->b_d->a_ii_v(c::x_i, c::y_i);
      (this->j_Ai[this->t_i] = (d::__ci(),d::g_i));
      (this->k_Ai[this->t_i] = (d::__ci(),d::h_i));
      (this->a_Az[this->t_i] = L_var7);
      L_var1->b_d->a_ii_v(L_var5, L_var6);
      (this->l_Ai[this->t_i] = (d::__ci(),d::g_i));
      (this->m_Ai[this->t_i] = (d::__ci(),d::h_i));
   }
   float L_var9 = (((float)((o::__ci(),o::a_i))) / 1000.0f);
   L_var1->b_d->a_ii_v(c::x_i, c::y_i);
   (L_var4 = (d::__ci(),d::g_i));
   (L_var5 = (d::__ci(),d::h_i));
   L_var1->a_d_v(j::a_d);
   j::a_d->a_ii_v(c::x_i, c::y_i);
   (L_var6 = jf2i(((L_var9 * 65536.0f))));
   (this->n_Ai[this->t_i] = jwrap32(jwint(jwrap32(jwint((d::__ci(),d::g_i)) - jwint(L_var4))) + jwint(jwrap32(jwint(L_var6) * jwint(0)))));
   (this->o_Ai[this->t_i] = jwrap32(jwint(jwrap32(jwint((d::__ci(),d::h_i)) - jwint(L_var5))) + jwint(jwrap32(jwint(L_var6) * jwint(0)))));
   (this->t_i++);
   if ((L_var1->a_s > (-1))) {
      (jdown<g>(this->a__j()->a_s_j(L_var1->a_s)))->a_i_v(2);
   }
}
bool c::c_iiiiiiii_z(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7) {
   int64_t L_var8 = ((int64_t)((jwrap32(jwint(L_var0) - jwint(L_var5)))));
   int64_t L_var10 = ((int64_t)((jwrap32(jwint(L_var1) - jwint(L_var6)))));
   int64_t L_var12{};
   if ((((L_var12 = jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(L_var8) * jwlong(((int64_t)(L_var2))))) + jwlong(jwrap64(jwlong(L_var10) * jwlong(((int64_t)(L_var3))))))),16))) >= (int64_t)0LL)) {
      return false;
   } else {
      int64_t L_var14{};
      if ((((L_var14 = jwrap64(jwlong((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(L_var8) * jwlong(L_var8))) + jwlong(jwrap64(jwlong(L_var10) * jwlong(L_var10))))),16))) - jwlong(((int64_t)((jshl(int32_t(jwrap32(jwint(L_var7) * jwint(L_var7))),16)))))))) <= (int64_t)0LL)) {
         (c::z_i = 0);
         int32_t L_var22 = jf2i(std::sqrt(((double)((jwrap64(jwlong(jwrap64(jwlong(L_var8) * jwlong(L_var8))) + jwlong(jwrap64(jwlong(L_var10) * jwlong(L_var10)))))))));
         int32_t L_var17 = 0;
         int32_t L_var23 = 0;
         if ((L_var22 != 0)) {
            (L_var17 = ((int32_t)((jdiv(int64_t((jshl(int64_t(jwrap64(jwlong(L_var8) * jwlong(((int64_t)(L_var7))))),16))),int64_t(((int64_t)(L_var22))))))));
            (L_var23 = ((int32_t)((jdiv(int64_t((jshl(int64_t(jwrap64(jwlong(L_var10) * jwlong(((int64_t)(L_var7))))),16))),int64_t(((int64_t)(L_var22))))))));
         }
         (c::x_i = jwrap32(jwint(L_var5) + jwint(L_var17)));
         (c::y_i = jwrap32(jwint(L_var6) + jwint(L_var23)));
         (c::i_z = true);
         return true;
      } else {
         int64_t L_var16{};
         if ((((L_var16 = jwrap64(jwlong((jshr(int64_t(jwrap64(jwlong(L_var12) * jwlong(L_var12))),16))) - jwlong(L_var14)))) < (int64_t)0LL)) {
            return false;
         } else {
            int64_t L_var18{};
            int64_t L_var20{};
            if (([&]() { auto __l123 = ((L_var18 = ([&]() { auto __l121 = (-L_var12); auto __r122 = ((int64_t)((jf2i(std::sqrt(((double)(((L_var20 = jshl(int64_t(L_var16),16)))))))))); return jwrap64(jwlong(__l121) - jwlong(__r122)); }()))); auto __r124 = ((int64_t)(L_var4)); return (__l123 <= __r124); }())) {
               (c::z_i = ((int32_t)((jdiv(int64_t((jshl(int64_t(L_var18),16))),int64_t(((int64_t)(L_var4))))))));
               (c::x_i = ((int32_t)((jwrap64(jwlong(((int64_t)(L_var0))) + jwlong((jshr(int64_t(jwrap64(jwlong(L_var18) * jwlong(((int64_t)(L_var2))))),16))))))));
               (c::y_i = ((int32_t)((jwrap64(jwlong(((int64_t)(L_var1))) + jwlong((jshr(int64_t(jwrap64(jwlong(L_var18) * jwlong(((int64_t)(L_var3))))),16))))))));
               (c::i_z = false);
               return true;
            } else {
               return false;
            }
         }
      }
   }
}
bool c::a_iiiiiiiii_z(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, int32_t L_var8) {
   int64_t L_var9 = jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var4))) * jwlong(((int64_t)(L_var3))))),16);
   int64_t L_var11 = jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var5))) * jwlong(((int64_t)(L_var2))))),16);
   int64_t L_var13 = jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var6))) * jwlong(((int64_t)(L_var3))))),16);
   int64_t L_var15 = jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var7))) * jwlong(((int64_t)(L_var2))))),16);
   int64_t L_var17{};
   if ((((L_var17 = jwrap64(jwlong(jwrap64(jwlong(jwrap64(jwlong(L_var9) - jwlong(L_var11))) - jwlong(L_var13))) + jwlong(L_var15)))) == (int64_t)0LL)) {
      return false;
   } else {
      int64_t L_var19{};
      if (((((L_var19 = jdiv(int64_t((jshl(int64_t(jwrap64(jwlong(jwrap64(jwlong(jwrap64(jwlong(L_var9) - jwlong(L_var11))) + jwlong((jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var2))) * jwlong(((int64_t)(L_var1))))),16))))) - jwlong((jshr(int64_t(jwrap64(jwlong(((int64_t)(L_var3))) * jwlong(((int64_t)(L_var0))))),16))))),16))),int64_t(L_var17)))) >= (int64_t)0LL) && (L_var19 <= (int64_t)65536LL))) {
         int64_t L_var21{};
         if (((((L_var21 = jdiv(int64_t((jwrap64(jwlong(jwrap64(jwlong(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var4))) * jwlong(((int64_t)((jwrap32(jwint(L_var7) - jwint(L_var1)))))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var5))) * jwlong(((int64_t)((jwrap32(jwint(L_var0) - jwint(L_var6)))))))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var6))) * jwlong(((int64_t)(L_var1))))))) - jwlong(jwrap64(jwlong(((int64_t)(L_var7))) * jwlong(((int64_t)(L_var0)))))))),int64_t(L_var17)))) >= (int64_t)0LL) && (L_var21 <= (int64_t)65536LL))) {
            (c::z_i = ((int32_t)(L_var21)));
            (c::x_i = ((int32_t)((jwrap64(jwlong(((int64_t)(L_var0))) + jwlong((jshr(int64_t(jwrap64(jwlong(L_var21) * jwlong(((int64_t)(L_var2))))),16))))))));
            (c::y_i = ((int32_t)((jwrap64(jwlong(((int64_t)(L_var1))) + jwlong((jshr(int64_t(jwrap64(jwlong(L_var21) * jwlong(((int64_t)(L_var3))))),16))))))));
            (c::i_z = false);
            return true;
         } else {
            if ((L_var21 < (int64_t)0LL)) {
               int64_t L_var23 = ((int64_t)((jwrap32(jwint(L_var6) - jwint(L_var4)))));
               int64_t L_var25 = ((int64_t)((jwrap32(jwint(L_var7) - jwint(L_var5)))));
               int64_t L_var27 = ((int64_t)((jwrap32(jwint(L_var0) - jwint(L_var4)))));
               int64_t L_var29 = ((int64_t)((jwrap32(jwint(L_var1) - jwint(L_var5)))));
               int64_t L_var31{};
               if ((((L_var31 = jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(L_var27) * jwlong(L_var23))) + jwlong(jwrap64(jwlong(L_var29) * jwlong(L_var25))))),16))) <= (int64_t)0LL)) {
                  return false;
               } else {
                  int64_t L_var33 = jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(L_var23) * jwlong(L_var23))) + jwlong(jwrap64(jwlong(L_var25) * jwlong(L_var25))))),16);
                  if ((L_var31 >= L_var33)) {
                     return false;
                  } else {
                     (L_var31 = jdiv(int64_t((jshl(int64_t(L_var31),16))),int64_t(L_var33)));
                     int64_t L_var35 = jwrap64(jwlong(((int64_t)(L_var4))) + jwlong((jshr(int64_t(jwrap64(jwlong(L_var31) * jwlong(L_var23))),16))));
                     int64_t L_var37 = jwrap64(jwlong(((int64_t)(L_var5))) + jwlong((jshr(int64_t(jwrap64(jwlong(L_var31) * jwlong(L_var25))),16))));
                     int64_t L_var39 = jwrap64(jwlong(L_var35) - jwlong(((int64_t)(L_var0))));
                     int64_t L_var41 = jwrap64(jwlong(L_var37) - jwlong(((int64_t)(L_var1))));
                     if ((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(L_var39) * jwlong(L_var39))) + jwlong(jwrap64(jwlong(L_var41) * jwlong(L_var41))))),16) > ((int64_t)(L_var8)))) {
                        return false;
                     } else {
                        (c::z_i = 0);
                        (c::x_i = ((int32_t)(L_var35)));
                        (c::y_i = ((int32_t)(L_var37)));
                        (c::i_z = true);
                        return true;
                     }
                  }
               }
            } else {
               return false;
            }
         }
      } else {
         return false;
      }
   }
}
void c::e__v() {
   this->h__v();
   j::d__v();
   this->n__v();
   int32_t L_var1{};
   if ((((L_var1 = jwrap32(jwint(3000) - jwint((m::__ci(),m::c_i))))) <= 1000)) {
      (this->c_d->f_i = jwrap32(jwint((m::__ci(),m::d_i)) + jwint((jshl(int32_t((m::__ci(),m::b_As)[jrem(int32_t(jdiv(int32_t(L_var1),int32_t(5))),int32_t(360))]),14)))));
   } else {
      (this->c_d->f_i = jwrap32(jwint(jwrap32(jwint((m::__ci(),m::d_i)) + jwint((jshl(int32_t((m::__ci(),m::b_As)[200]),14))))) - jwint(jwrap32(jwint((jwrap32(jwint(L_var1) - jwint(1000)))) * jwint(22500)))));
   }
}
void c::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   if (this->b_z) {
      this->a_d_v(j::a_d);
      (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
      (d::__ci(),d::a_d)->a_ii_v(this->c_d->c_i, this->c_d->f_i);
      int32_t L_var19 = jshr(int32_t((d::__ci(),d::a_d)->c_i),16);
      int32_t L_var20 = jshr(int32_t((d::__ci(),d::a_d)->f_i),16);
      (d::__ci(),d::a_d)->a_ii_v((-(jshl(int32_t(c::a_Ai[this->d_i]),16))), jshl(int32_t(c::a_Ai[this->d_i]),16));
      int32_t L_var4 = jshr(int32_t((d::__ci(),d::g_i)),16);
      int32_t L_var5 = jshr(int32_t((d::__ci(),d::h_i)),16);
      int32_t L_var6 = jwrap32(jwint(L_var19) - jwint(L_var4));
      int32_t L_var7 = jwrap32(jwint(L_var20) - jwint(L_var5));
      int32_t L_var8 = jshr(int32_t(L_var6),2);
      int32_t L_var9 = jwrap32(jwint(L_var19) - jwint(L_var8));
      int32_t L_var10 = jwrap32(jwint(L_var20) - jwint(L_var8));
      if ((!this->h_z)) {
         L_var1->setColor(this->u_i);
         L_var1->fillArc(L_var4, L_var5, jshl(int32_t(L_var6),1), jshl(int32_t(L_var7),1), 0, 360);
      } else {
         if ((this->d_i == 0)) {
            (L_var6 = L_var19);
            (L_var7 = L_var20);
            JGraphics L_var21 = (o::__ci(), o::a__Graphics());
            if ((this->a_i != 0)) {
               (m::__ci(),m::a_Graphics)->setColor(255);
               ([&]() -> decltype(auto) { auto __p125 = 0; auto __p126 = 0; auto __p127 = (m::__ci(),m::a_Image)->getWidth(); auto __p128 = (m::__ci(),m::a_Image)->getHeight(); return (m::__ci(),m::a_Graphics)->fillRect(__p125, __p126, __p127, __p128); }());
               (L_var19 = jshr(int32_t((m::__ci(),m::a_Image)->getWidth()),1));
               (L_var20 = jshr(int32_t((m::__ci(),m::a_Image)->getHeight()),1));
               (L_var1 = (m::__ci(),m::a_Graphics));
               (o::__ci(), o::a_Graphics_v((m::__ci(),m::a_Graphics)));
            }
            for (int32_t L_var23 = 0; (L_var23 < 4); (L_var23++)) {
               {
                  (this->h_Ai[L_var23] = 0);
                  for (int32_t L_var35 = 0; (L_var35 < 4); (L_var35++)) {
                     {
                        if ((L_var23 != L_var35)) {
                           (this->h_Ai[L_var23] = jwrap32(jwint(this->h_Ai[L_var23]) - jwint((jshr(int32_t(this->f_Ai[L_var35]),1)))));
                        }
                     }
                  }
               }
            }
            for (int32_t L_var24 = 0; (L_var24 < 4); (L_var24++)) {
               {
                  (this->i_Ai[L_var24] = 999);
               }
            }
            this->a_iiiiiGraphicszz_v(L_var19, L_var20, jwrap32(jwint(c::b_Ai[this->d_i]) + jwint(2)), jwrap32(jwint(c::b_Ai[this->d_i]) + jwint(2)), (-16777216), L_var1, false, false);
            this->a_iiiiiGraphicszz_v(L_var19, L_var20, c::b_Ai[this->d_i], c::b_Ai[this->d_i], this->u_i, L_var1, true, false);
            (L_var5 = jdiv(int32_t(jwrap32(jwint(c::b_Ai[this->d_i]) * jwint(90))),int32_t(100)));
            this->a_iiiiiGraphicszz_v(L_var19, jwrap32(jwint(L_var20) + jwint(2)), L_var5, c::b_Ai[this->d_i], this->w_i, L_var1, false, false);
            this->a_iiiiiGraphicszz_v(jwrap32(jwint(L_var19) + jwint(1)), jwrap32(jwint(L_var20) - jwint(1)), L_var5, c::b_Ai[this->d_i], this->u_i, L_var1, false, true);
            (d::__ci(),d::a_d)->a_f_v(5.3f);
            (L_var5 = jshr(int32_t(((L_var8 = this->i_Ai[1]))),1));
            (L_var8 = jwrap32(jwint(jwrap32(jwint(this->i_Ai[1]) - jwint(L_var5))) + jwint(1)));
            (L_var9 = jwrap32(jwint(L_var19) + jwint((jshr(int32_t(jwrap32(jwint((d::__ci(),d::a_d)->a_i) * jwint(L_var8))),16)))));
            (L_var8 = jwrap32(jwint(L_var20) + jwint((jshr(int32_t(jwrap32(jwint((d::__ci(),d::a_d)->d_i) * jwint(L_var8))),16)))));
            for (int32_t L_var42 = 0; (L_var42 < 12); (L_var42++)) {
               {
                  int32_t L_var11 = jwrap32(jwint(31) + jwint(jmath_abs<int32_t>(jrem(int32_t(L_var42),int32_t(2)))));
                  float L_var12 = (this->n_f + (((float)(L_var42)) * 0.8f));
                  int32_t L_var13 = jwrap32(jwint(100) - jwint((jshl(int32_t(L_var42),2))));
                  int32_t L_var14 = L_var13;
                  (L_var13 = L_var20);
                  int32_t L_var49 = L_var19;
                  c* L_var45 = this;
                  (d::__ci(),d::a_d)->a_f_v(L_var12);
                  for (int32_t L_var53 = 0; (L_var53 < 4); (L_var53++)) {
                     {
                        int32_t L_var17 = jshr(int32_t(jshr(int32_t(L_var45->i_Ai[L_var53]),1)),1);
                        (L_var17 = jdiv(int32_t(jwrap32(jwint(L_var14) * jwint((jwrap32(jwint(L_var45->i_Ai[L_var53]) - jwint(L_var17)))))),int32_t(100)));
                        int32_t L_var18 = jwrap32(jwint(L_var49) + jwint((jshr(int32_t(jwrap32(jwint((d::__ci(),d::a_d)->a_i) * jwint(L_var17))),16))));
                        (L_var17 = jwrap32(jwint(L_var13) + jwint((jshr(int32_t(jwrap32(jwint((d::__ci(),d::a_d)->d_i) * jwint(L_var17))),16)))));
                        if ((L_var53 == 0)) {
                           if (((L_var18 >= L_var49) && (L_var17 <= L_var13))) {
                              (o::__ci(), o::a_iii_v(L_var18, jwrap32(jwint(L_var17) + jwint((jshr(int32_t(jwrap32(jwint(L_var45->f_Ai[1]) + jwint(L_var45->h_Ai[1]))),10)))), L_var11));
                              break;
                           }
                        } else {
                           if ((L_var53 == 1)) {
                              if (((L_var18 <= L_var49) && (L_var17 <= L_var13))) {
                                 (o::__ci(), o::a_iii_v(L_var18, jwrap32(jwint(L_var17) + jwint((jshr(int32_t(jwrap32(jwint(L_var45->f_Ai[1]) + jwint(L_var45->h_Ai[1]))),10)))), L_var11));
                                 break;
                              }
                           } else {
                              if ((L_var53 == 2)) {
                                 if (((L_var18 <= L_var49) && (L_var17 >= L_var13))) {
                                    (o::__ci(), o::a_iii_v(L_var18, jwrap32(jwint(L_var17) + jwint((jshr(int32_t(jwrap32(jwint(L_var45->f_Ai[1]) + jwint(L_var45->h_Ai[1]))),10)))), L_var11));
                                    break;
                                 }
                              } else {
                                 if (((L_var18 >= L_var49) && (L_var17 >= L_var13))) {
                                    (o::__ci(), o::a_iii_v(L_var18, jwrap32(jwint(L_var17) + jwint((jshr(int32_t(jwrap32(jwint(L_var45->f_Ai[1]) + jwint(L_var45->h_Ai[1]))),10)))), L_var11));
                                    break;
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
            (o::__ci(), o::a_iii_v(L_var19, L_var20, 17));
            this->a_iiiiiGraphicszz_v(L_var9, L_var8, jshr(int32_t(L_var5),1), c::b_Ai[this->d_i], this->v_i, L_var1, false, false);
            (o::__ci(), o::a_iii_v(L_var19, L_var20, 28));
            if ((this->a_i != 0)) {
               (o::__ci(), o::a_Graphics_v(L_var21));
               ([&]() -> decltype(auto) { auto __p129 = (m::__ci(),m::a_Ai); auto __p130 = 0; auto __p131 = (m::__ci(),m::a_Image)->getWidth(); auto __p132 = 0; auto __p133 = 0; auto __p134 = (m::__ci(),m::a_Image)->getWidth(); auto __p135 = (m::__ci(),m::a_Image)->getHeight(); return (m::__ci(),m::a_Image)->getRGB(__p129, __p130, __p131, __p132, __p133, __p134, __p135); }());
               (L_var10 = 0);
               for (int32_t L_var46 = 0; ([&]() { auto __l136 = L_var46; auto __r137 = (m::__ci(),m::a_Image)->getHeight(); return (__l136 < __r137); }()); (L_var46++)) {
                  {
                     for (int32_t L_var50 = 0; ([&]() { auto __l138 = L_var50; auto __r139 = (m::__ci(),m::a_Image)->getWidth(); return (__l138 < __r139); }()); (L_var50++)) {
                        {
                           if (((m::__ci(),m::a_Ai)[L_var10] == (-16776961))) {
                              ((m::__ci(),m::a_Ai)[L_var10] = 0);
                           } else {
                              ((m::__ci(),m::a_Ai)[L_var10] = jwrap32(jwint((m::__ci(),m::a_Ai)[L_var10]) - jwint(this->a_i)));
                           }
                           (L_var10++);
                        }
                     }
                  }
               }
               int32_t L_var47 = ([&]() { auto __l140 = L_var6; auto __r141 = (jshr(int32_t((m::__ci(),m::a_Image)->getWidth()),1)); return jwrap32(jwint(__l140) - jwint(__r141)); }());
               int32_t L_var51 = ([&]() { auto __l142 = L_var7; auto __r143 = (jshr(int32_t((m::__ci(),m::a_Image)->getHeight()),1)); return jwrap32(jwint(__l142) - jwint(__r143)); }());
               ([&]() -> decltype(auto) { auto __p144 = (m::__ci(),m::a_Ai); auto __p145 = 0; auto __p146 = (m::__ci(),m::a_Image)->getWidth(); auto __p147 = L_var47; auto __p148 = L_var51; auto __p149 = (m::__ci(),m::a_Image)->getWidth(); auto __p150 = (m::__ci(),m::a_Image)->getHeight(); auto __p151 = true; return (o::__ci(), o::a__Graphics())->drawRGB(__p144, __p145, __p146, __p147, __p148, __p149, __p150, __p151); }());
            }
            if (((m::__ci(),m::d_z) && (!(m::__ci(),m::b_z)))) {
               (L_var10 = ([&]() { auto __l152 = (o::__ci(),o::a_i); auto __r153 = (o::__ci(), o::a__i()); return jwrap32(jwint(__l152) * jwint(__r153)); }()));
               (this->r_i += L_var10);
               if ((this->r_i > 150)) {
                  int32_t L_var48 = jdiv(int32_t((g::__ci(),g::a_Ai)[4]),int32_t(120));
                  (m::__ci(),m::d_n)->b_iiiiiiiiii_v(L_var48, (m::__ci(),m::a_c)->c_d->c_i, (m::__ci(),m::a_c)->c_d->f_i, jshl(int32_t(c::a_Ai[0]),15), 0, 0, 0, 0, 1000, 166);
                  (this->r_i = 0);
               }
            }
         } else {
            if ((this->d_i == 1)) {
               float L_var28 = 11.25f;
               (L_var7 = jf2i(jtoDegrees(((double)(this->n_f)))));
               while ((L_var7 < 0)) {
                  {
                     (L_var7 += 360);
                  }
               }
               while ((L_var7 > 359)) {
                  {
                     (L_var7 -= 360);
                  }
               }
               (L_var4 = jwrap32(jwint(31) - jwint(jf2i(((((float)(L_var7)) / L_var28))))));
               (o::__ci(), o::a_iii_v(L_var19, L_var20, ((int32_t)(c::a_As[L_var4]))));
            } else {
               if ((this->d_i == 2)) {
                  (L_var6 = jshl(int32_t(c::b_Ai[this->d_i]),1));
                  L_var1->setColor(0);
                  L_var1->fillArc(jwrap32(jwint(L_var4) - jwint(2)), jwrap32(jwint(L_var5) - jwint(2)), jwrap32(jwint(L_var6) + jwint(4)), jwrap32(jwint(L_var6) + jwint(4)), 0, 360);
                  for (int32_t L_var33 = 0; (L_var33 < 6); (L_var33++)) {
                     {
                        L_var1->setColor(c::p_Ai[L_var33]);
                        ([&]() -> decltype(auto) { auto __p156 = L_var4; auto __p157 = L_var5; auto __p158 = L_var6; auto __p159 = L_var6; auto __p160 = ([&]() { auto __l154 = jwrap32(jwint(L_var33) * jwint(60)); auto __r155 = jf2i(jtoDegrees(((double)(this->n_f)))); return jwrap32(jwint(__l154) - jwint(__r155)); }()); auto __p161 = 60; return L_var1->fillArc(__p156, __p157, __p158, __p159, __p160, __p161); }());
                     }
                  }
                  L_var1->setColor(c::p_Ai[0]);
                  L_var1->fillArc(L_var9, L_var10, jshl(int32_t(L_var8),1), jshl(int32_t(L_var8),1), 0, 360);
                  (o::__ci(), o::a_iii_v(L_var19, L_var20, 5));
               }
            }
         }
         if (((c::c_i == 1) || ((g::__ci(),g::a_Ai)[0] == 3))) {
            (o::__ci(), o::a_iii_v(L_var19, L_var20, 20));
            return;
         }
         if (((c::c_i == 2) || (c::c_i == 3))) {
            int32_t L_var30 = 462;
            int32_t L_var34 = 2;
            if ((c::c_i == 3)) {
               (L_var30 = 447);
               (L_var34 = 4);
            }
            if (([&]() { auto __l162 = ((L_var8 = jdiv(int32_t(jwrap32(jwint(c::s_i) * jwint(L_var34))),int32_t(600)))); auto __r163 = jwrap32(jwint(L_var34) - jwint(1)); return (__l162 > __r163); }())) {
               (L_var8 = jwrap32(jwint(L_var34) - jwint(1)));
            }
            (L_var8 = jwrap32(jwint(jwrap32(jwint(L_var34) - jwint(1))) - jwint(L_var8)));
            (o::__ci(), o::b_iiii_v(L_var19, L_var20, L_var30, L_var8));
            return;
         }
         if (((c::c_i >= 4) && (c::c_i <= 8))) {
            (o::__ci(), o::b_iiii_v(L_var19, L_var20, c::c_Ai[jwrap32(jwint(c::c_i) - jwint(4))], 0));
            return;
         }
         if (((g::__ci(),g::a_Ai)[0] == 4)) {
            (o::__ci(), o::b_iiii_v(L_var19, L_var20, 465, 0));
            return;
         }
      }
   }
}
void c::f__v() {
   (this->d_i++);
   if ((this->d_i > 2)) {
      (this->d_i = 0);
   }
   int32_t L_var1 = (m::__ci(), m::a__i());
   if ((this->d_i > L_var1)) {
      (this->d_i = 0);
   }
   this->a__v();
}
void c::g__v() {
   (this->a_f = 0.0f);
   (this->b_f = 0.0f);
   (this->f_f = 0.0f);
   (this->g_f = 0.0f);
   (this->d_f = 0.0f);
   (this->e_f = 0.0f);
   (this->j_f = 0.0f);
   (this->k_f = 0.0f);
}
void c::a_iiiiiGraphicszz_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, JGraphics L_var6, bool L_var7, bool L_var8) {
   L_var6->setColor(L_var5);
   (L_var5 = 2);
   for (int32_t L_var9 = 0; (L_var9 < 4); (L_var9++)) {
      {
         int32_t L_var10 = jwrap32(jwint(L_var3) - jwint(jdiv(int32_t(jwrap32(jwint(L_var3) * jwint((jshr(int32_t(jwrap32(jwint(this->f_Ai[L_var5]) + jwint(this->h_Ai[L_var5]))),10))))),int32_t(L_var4))));
         int32_t L_var11 = jwrap32(jwint(L_var3) - jwint(jdiv(int32_t(jwrap32(jwint(L_var3) * jwint((jshr(int32_t(jwrap32(jwint(this->f_Ai[jshr(int32_t(L_var9),1)]) + jwint(this->h_Ai[jshr(int32_t(L_var9),1)]))),10))))),int32_t(L_var4))));
         if (L_var8) {
            (L_var10++);
         }
         if (L_var7) {
            (this->i_Ai[L_var9] = L_var10);
            if ((L_var11 < L_var10)) {
               (this->i_Ai[L_var9] = L_var11);
            }
         }
         int32_t L_var12 = jwrap32(jwint(L_var1) - jwint(L_var10));
         int32_t L_var13 = jwrap32(jwint(L_var2) - jwint(L_var11));
         L_var6->fillArc(L_var12, jwrap32(jwint(L_var13) + jwint((jshr(int32_t(jwrap32(jwint(this->f_Ai[1]) + jwint(this->h_Ai[1]))),10)))), jshl(int32_t(L_var10),1), jshl(int32_t(L_var11),1), jwrap32(jwint(L_var9) * jwint(90)), 90);
         if ((L_var9 == 0)) {
            (L_var5++);
         }
         if ((L_var9 == 2)) {
            (L_var5--);
         }
      }
   }
}
void d::__clinit() {
   __inited = true;
   a_d = (d::__ci(), new d());
}
d::d() {
   this->a_i = 65536;
   this->e_i = 65536;
}
void d::a_ii_v(int32_t L_var1, int32_t L_var2) {
   (d::g_i = jwrap32(jwint(((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->a_i))) * jwlong(((int64_t)(L_var1))))) + jwlong(jwrap64(jwlong(((int64_t)(this->b_i))) * jwlong(((int64_t)(L_var2))))))),16))))) + jwint(this->c_i)));
   (d::h_i = jwrap32(jwint(((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->d_i))) * jwlong(((int64_t)(L_var1))))) + jwlong(jwrap64(jwlong(((int64_t)(this->e_i))) * jwlong(((int64_t)(L_var2))))))),16))))) + jwint(this->f_i)));
}
void d::b_ii_v(int32_t L_var1, int32_t L_var2) {
   (d::g_i = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->a_i))) * jwlong(((int64_t)(L_var1))))) + jwlong(jwrap64(jwlong(((int64_t)(this->b_i))) * jwlong(((int64_t)(L_var2))))))),16)))));
   (d::h_i = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->d_i))) * jwlong(((int64_t)(L_var1))))) + jwlong(jwrap64(jwlong(((int64_t)(this->e_i))) * jwlong(((int64_t)(L_var2))))))),16)))));
}
void d::a_d_v(d* L_var1) {
   (this->a_i = L_var1->a_i);
   (this->b_i = L_var1->b_i);
   (this->c_i = L_var1->c_i);
   (this->d_i = L_var1->d_i);
   (this->e_i = L_var1->e_i);
   (this->f_i = L_var1->f_i);
}
void d::b_d_v(d* L_var1) {
   int32_t L_var2 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->a_i))) * jwlong(((int64_t)(L_var1->a_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->b_i))) * jwlong(((int64_t)(L_var1->d_i))))))),16))));
   int32_t L_var3 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->a_i))) * jwlong(((int64_t)(L_var1->b_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->b_i))) * jwlong(((int64_t)(L_var1->e_i))))))),16))));
   int32_t L_var4 = ((int32_t)((jwrap64(jwlong((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->a_i))) * jwlong(((int64_t)(L_var1->c_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->b_i))) * jwlong(((int64_t)(L_var1->f_i))))))),16))) + jwlong(((int64_t)(this->c_i)))))));
   int32_t L_var5 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->d_i))) * jwlong(((int64_t)(L_var1->a_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->e_i))) * jwlong(((int64_t)(L_var1->d_i))))))),16))));
   int32_t L_var6 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->d_i))) * jwlong(((int64_t)(L_var1->b_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->e_i))) * jwlong(((int64_t)(L_var1->e_i))))))),16))));
   int32_t L_var7 = ((int32_t)((jwrap64(jwlong((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->d_i))) * jwlong(((int64_t)(L_var1->c_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->e_i))) * jwlong(((int64_t)(L_var1->f_i))))))),16))) + jwlong(((int64_t)(this->f_i)))))));
   (this->a_i = L_var2);
   (this->b_i = L_var3);
   (this->c_i = L_var4);
   (this->d_i = L_var5);
   (this->e_i = L_var6);
   (this->f_i = L_var7);
}
void d::a_ddd_v(d* L_var0, d* L_var1, d* L_var2) {
   int32_t L_var3 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var0->a_i))) * jwlong(((int64_t)(L_var1->a_i))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var0->b_i))) * jwlong(((int64_t)(L_var1->d_i))))))),16))));
   int32_t L_var4 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var0->a_i))) * jwlong(((int64_t)(L_var1->b_i))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var0->b_i))) * jwlong(((int64_t)(L_var1->e_i))))))),16))));
   int32_t L_var5 = ((int32_t)((jwrap64(jwlong((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var0->a_i))) * jwlong(((int64_t)(L_var1->c_i))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var0->b_i))) * jwlong(((int64_t)(L_var1->f_i))))))),16))) + jwlong(((int64_t)(L_var0->c_i)))))));
   int32_t L_var6 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var0->d_i))) * jwlong(((int64_t)(L_var1->a_i))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var0->e_i))) * jwlong(((int64_t)(L_var1->d_i))))))),16))));
   int32_t L_var7 = ((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var0->d_i))) * jwlong(((int64_t)(L_var1->b_i))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var0->e_i))) * jwlong(((int64_t)(L_var1->e_i))))))),16))));
   int32_t L_var8 = ((int32_t)((jwrap64(jwlong((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(L_var0->d_i))) * jwlong(((int64_t)(L_var1->c_i))))) + jwlong(jwrap64(jwlong(((int64_t)(L_var0->e_i))) * jwlong(((int64_t)(L_var1->f_i))))))),16))) + jwlong(((int64_t)(L_var0->f_i)))))));
   (L_var2->a_i = L_var3);
   (L_var2->b_i = L_var4);
   (L_var2->c_i = L_var5);
   (L_var2->d_i = L_var6);
   (L_var2->e_i = L_var7);
   (L_var2->f_i = L_var8);
}
void d::c_d_v(d* L_var1) {
   int64_t L_var2{};
   if ((((L_var2 = jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->a_i))) * jwlong(((int64_t)(this->e_i))))) - jwlong(jwrap64(jwlong(((int64_t)(this->b_i))) * jwlong(((int64_t)(this->d_i))))))),16))) != (int64_t)0LL)) {
      (L_var1->a_i = ((int32_t)((jdiv(int64_t((jshl(int64_t(((int64_t)(this->e_i))),16))),int64_t(L_var2))))));
      (L_var1->b_i = ((int32_t)((jdiv(int64_t((jshl(int64_t(((int64_t)(this->d_i))),16))),int64_t(L_var2))))));
      (L_var1->d_i = ((int32_t)((jdiv(int64_t((jshl(int64_t(((int64_t)(this->b_i))),16))),int64_t(L_var2))))));
      (L_var1->e_i = ((int32_t)((jdiv(int64_t((jshl(int64_t(((int64_t)(this->a_i))),16))),int64_t(L_var2))))));
      (L_var1->c_i = (-(((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->c_i))) * jwlong(((int64_t)(L_var1->a_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->f_i))) * jwlong(((int64_t)(L_var1->b_i))))))),16)))))));
      (L_var1->f_i = (-(((int32_t)((jshr(int64_t(jwrap64(jwlong(jwrap64(jwlong(((int64_t)(this->c_i))) * jwlong(((int64_t)(L_var1->d_i))))) + jwlong(jwrap64(jwlong(((int64_t)(this->f_i))) * jwlong(((int64_t)(L_var1->e_i))))))),16)))))));
   } else {
      jthrow(JArithmeticException::make(JS(u"Non-invertible matrix.")));
   }
}
void d::a_f_v(float L_var1) {
   int32_t L_var2 = jf2i(((((float)(std::cos(((double)(L_var1))))) * 65536.0f)));
   int32_t L_var3 = jf2i(((((float)(std::sin(((double)(L_var1))))) * 65536.0f)));
   (this->a_i = L_var2);
   (this->b_i = (-L_var3));
   (this->d_i = L_var3);
   (this->e_i = L_var2);
}
JString d::toString__String() {
   return JString::make(jcat(jcat(jcat(jcat(jcat(jcat(jcat(jcat(jcat(jcat(this->a_i,JS(u" ")),this->b_i),JS(u" ")),this->c_i),JS(u"\n")),this->d_i),JS(u" ")),this->e_i),JS(u" ")),this->f_i));
}
void e::__clinit() {
   __inited = true;
   j::__ci();
}
e::e() {
   (this->c_b = ((int8_t)(8)));
}
int32_t e::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   (L_var2 = j::a_Abi_i(L_var1, L_var2));
   ([&]() -> decltype(auto) { auto& __a166 = this->a_s; auto __v167 = ((int16_t)((([&]() { auto __l164 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r165 = (L_var1[(L_var2++)] & 255); return (__l164 | __r165); }())))); return (__a166 = __v167); }());
   ([&]() -> decltype(auto) { auto& __a168 = this->a_b; auto __v169 = L_var1[(L_var2++)]; return (__a168 = __v169); }());
   (this->a_i = 0);
   (this->b_i = 0);
   (this->c_i = 0);
   int32_t L_var3{};
   if ((((L_var3 = (m::__ci(), m::b_i_i((m::__ci(),m::f_i))))) == 0)) {
      (this->a_s = ((int16_t)(497)));
   }
   if ((L_var3 == 1)) {
      (this->a_s = ((int16_t)(509)));
   }
   if ((L_var3 == 2)) {
      (this->a_s = ((int16_t)(490)));
   }
   return L_var2;
}
void e::a__v() {
   (this->e_i = (-4587520));
   (this->g_i = 4587520);
   (this->f_i = 0);
   (this->h_i = 6225920);
}
void e::d__v() {
   j::d__v();
   if ((this->a_i < this->b_i)) {
      int32_t L_var1 = (o::__ci(),o::a_i);
      (this->a_i += L_var1);
      if (([&]() { auto __l174 = this->a_i; auto __r175 = ([&]() { auto __l172 = this->b_i; auto __r173 = ([&]() { auto __l170 = this->b_i; auto __r171 = (o::__ci(), o::b_i_i(((int32_t)(this->a_s)))); return jdiv(int32_t(__l170),int32_t(__r171)); }()); return jwrap32(jwint(__l172) - jwint(__r173)); }()); return (__l174 >= __r175); }())) {
         if ((!this->a_z)) {
            (this->a_z = true);
            (this->a_c->a_z = true);
            (this->a_c->b_f = this->a_f);
            (this->a_c->j_f = 0.0f);
            (this->a_c->k_f = 0.0f);
            (this->a_c->c_z = true);
            if (this->a_c->equals((m::__ci(),m::a_c))) {
               ((g::__ci(),g::a_Ai)[1] = 0);
            }
         }
         (L_var1 = (o::__ci(), o::b_i_i(((int32_t)(this->a_s)))));
         (this->c_i = jdiv(int32_t(jwrap32(jwint(this->a_i) * jwint(L_var1))),int32_t(this->b_i)));
      } else {
         (L_var1 = (o::__ci(), o::b_i_i(((int32_t)(this->a_s)))));
         (this->c_i = jdiv(int32_t(jwrap32(jwint(this->a_i) * jwint(L_var1))),int32_t(this->b_i)));
         this->b__v();
      }
      if ((this->a_i >= this->b_i)) {
         (this->a_i = 0);
         (this->b_i = 0);
         (this->c_i = 0);
      }
   }
}
void e::b__v() {
   this->a_d_v(j::a_d);
   ([&]() -> decltype(auto) { auto& __a180 = this->a_c->c_d->f_i; auto __v181 = ([&]() { auto __l178 = j::a_d->f_i; auto __r179 = (jshl(int32_t(([&]() { auto __l176 = jwrap32(jwint(65536) * jwint(((int16_t)((o::__ci(), o::b_ii_i((o::__ci(), o::c_ii_i(((int32_t)(this->a_s)), this->c_i)), 0)))))); auto __r177 = j::g_d->a_i; return jdiv(int32_t(__l176),int32_t(__r177)); }())),16)); return jwrap32(jwint(__l178) - jwint(__r179)); }()); return (__a180 = __v181); }());
}
void e::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   this->a_d_v(j::a_d);
   (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
   int32_t L_var4 = jshr(int32_t((d::__ci(),d::a_d)->c_i),16);
   int32_t L_var5 = jshr(int32_t((d::__ci(),d::a_d)->f_i),16);
   (o::__ci(), o::b_iiii_v(L_var4, L_var5, ((int32_t)(this->a_s)), this->c_i));
}
void f::__clinit() {
   __inited = true;
}
f::f() {
   this->a_h = nullptr;
   this->a_z = true;
   this->a_i = (-1);
   this->a_String = nullptr;
}
f::f(JString L_var1, int32_t L_var2, h* L_var3, int32_t L_var4) {
   this->a_h = nullptr;
   this->a_z = true;
   this->a_i = (-1);
   this->a_String = nullptr;
   (this->a_h = L_var3);
   (this->a_i = L_var4);
   this->a_Stringi_v(L_var1, L_var2);
}
int32_t f::a__i() {
   if ((this->a_i_i(5) == 256)) {
      b* L_var1 = this->a_b;
      if ((this->a_b != nullptr)) {
         if (((L_var1->a_String != nullptr) && (L_var1->a_String.length() >= 1))) {
            return ([&]() { auto __l184 = ([&]() { auto __l182 = L_var1->b_i; auto __r183 = this->a_i_i(13); return jwrap32(jwint(__l182) + jwint(__r183)); }()); auto __r185 = this->a_i_i(14); return jwrap32(jwint(__l184) + jwint(__r185)); }());
         }
         return ([&]() { auto __l188 = ([&]() { auto __l186 = jwrap32(jwint(L_var1->b_i) - jwint((b::__ci(),b::a_i))); auto __r187 = this->a_i_i(13); return jwrap32(jwint(__l186) + jwint(__r187)); }()); auto __r189 = this->a_i_i(14); return jwrap32(jwint(__l188) + jwint(__r189)); }());
      }
      if ((this->a_h != nullptr)) {
         return this->a_h->b__i();
      }
   } else {
      if ((this->a_i_i(8) != 4096)) {
         return this->a_i_i(10);
      }
      if ((this->a_h != nullptr)) {
         return this->a_h->b__i();
      }
   }
   return 0;
}
int32_t f::b__i() {
   b* L_var1 = this->a_b;
   return ([&]() { auto __l192 = ([&]() { auto __l190 = (((this->a_b != nullptr) ? L_var1->c_i : 0)); auto __r191 = this->a_i_i(11); return jwrap32(jwint(__l190) + jwint(__r191)); }()); auto __r193 = this->a_i_i(12); return jwrap32(jwint(__l192) + jwint(__r193)); }());
}
bool f::a__z() {
   return (this->a_i != (-1));
}
void f::a_ii_v(int32_t L_var1, int32_t L_var2) {
   ([&]() -> decltype(auto) { auto& __a194 = this->a_Ai; auto __v195 = (h::__ci(), h::a_iiAii_Ai(L_var1, L_var2, this->a_Ai, 1)); return (__a194 = __v195); }());
}
int32_t f::a_i_i(int32_t L_var1) {
   return (((!(h::__ci(), h::a_iAi_z(L_var1, this->a_Ai))) && (this->a_h != nullptr)) ? (h::__ci(), h::a_iAii_i(L_var1, this->a_h->a_Ai, 1)) : (h::__ci(), h::a_iAii_i(L_var1, this->a_Ai, 1)));
}
void f::a_Stringi_v(JString L_var1, int32_t L_var2) {
   if ((L_var1 == nullptr)) {
      (L_var1 = JS(u""));
   }
   b* L_var3 = this->a_b;
   (this->a_b = nullptr);
   int32_t L_var4 = this->a__i();
   (this->a_b = L_var3);
   (L_var4 -= ([&]() { auto __l196 = this->a_i_i(13); auto __r197 = this->a_i_i(14); return jwrap32(jwint(__l196) + jwint(__r197)); }()));
   int32_t L_var6 = 0;
   for (int32_t L_var5 = 0; (L_var5 < 9); (L_var5++)) {
      {
         (L_var6 |= this->a_i_i(L_var5));
      }
   }
   ([&]() -> decltype(auto) { auto& __a203 = this->a_b; auto __v204 = ([&]() -> decltype(auto) { auto __p198 = L_var1; auto __p199 = L_var4; auto __p200 = this->a_i_i(9); auto __p201 = L_var6; auto __p202 = L_var2; return (b::__ci(), new b(__p198, __p199, __p200, __p201, __p202)); }()); return (__a203 = __v204); }());
}
void g::__clinit() {
   __inited = true;
   j::__ci();
   (g::c_Aj = newArr<j*>(2));
   (g::c_i = 0);
}
g::g() {
   (this->a_b = ((int8_t)(0)));
   (this->f_b = ((int8_t)(0)));
   (this->g_b = ((int8_t)((-1))));
   (this->a_Aj = newArr<j*>(2));
   (this->b_Aj = newArr<j*>(2));
   (this->c_b = ((int8_t)(3)));
}
int32_t g::a_Abi_i(Arr<int8_t> L_array, int32_t L_a_Abi_i) {
   (L_a_Abi_i = j::a_Abi_i(L_array, L_a_Abi_i));
   ([&]() -> decltype(auto) { auto& __a207 = this->e_i; auto __v208 = jshl(int32_t((([&]() { auto __l205 = jshl(int32_t(L_array[(L_a_Abi_i++)]),8); auto __r206 = ((L_array[(L_a_Abi_i++)] & 0xFF)); return (__l205 | __r206); }()))),16); return (__a207 = __v208); }());
   ([&]() -> decltype(auto) { auto& __a211 = this->h_i; auto __v212 = jshl(int32_t((([&]() { auto __l209 = jshl(int32_t(L_array[(L_a_Abi_i++)]),8); auto __r210 = ((L_array[(L_a_Abi_i++)] & 0xFF)); return (__l209 | __r210); }()))),16); return (__a211 = __v212); }());
   ([&]() -> decltype(auto) { auto& __a215 = this->g_i; auto __v216 = jshl(int32_t((([&]() { auto __l213 = jshl(int32_t(L_array[(L_a_Abi_i++)]),8); auto __r214 = ((L_array[(L_a_Abi_i++)] & 0xFF)); return (__l213 | __r214); }()))),16); return (__a215 = __v216); }());
   ([&]() -> decltype(auto) { auto& __a219 = this->f_i; auto __v220 = jshl(int32_t((([&]() { auto __l217 = jshl(int32_t(L_array[(L_a_Abi_i++)]),8); auto __r218 = ((L_array[(L_a_Abi_i++)] & 0xFF)); return (__l217 | __r218); }()))),16); return (__a219 = __v220); }());
   ([&]() -> decltype(auto) { auto& __a221 = this->a_b; auto __v222 = L_array[(L_a_Abi_i++)]; return (__a221 = __v222); }());
   if ((this->a_b == 2)) {
      (this->g_b = ((int8_t)(0)));
   }
   ([&]() -> decltype(auto) { auto& __a223 = this->d_b; auto __v224 = L_array[(L_a_Abi_i++)]; return (__a223 = __v224); }());
   ([&]() -> decltype(auto) { auto& __a225 = this->e_b; auto __v226 = L_array[(L_a_Abi_i++)]; return (__a225 = __v226); }());
   ([&]() -> decltype(auto) { auto& __a227 = this->a_s; auto __v228 = j::a_Abi_s(L_array, L_a_Abi_i); return (__a227 = __v228); }());
   (L_a_Abi_i += 2);
   ([&]() -> decltype(auto) { auto& __a229 = this->f_b; auto __v230 = L_array[(L_a_Abi_i++)]; return (__a229 = __v230); }());
   (this->a_AAb = newArr<Arr<int8_t>>(this->f_b));
   for (int8_t L_b = ((int8_t)(0)); (L_b < this->f_b); (++L_b)) {
      {
         int8_t L_b2 = L_array[(L_a_Abi_i++)];
         (this->a_AAb[L_b] = newArr<int8_t>(L_b2));
         for (int8_t L_b3 = ((int8_t)(0)); (L_b3 < L_b2); (++L_b3)) {
            {
               ([&]() -> decltype(auto) { auto& __a231 = this->a_AAb[L_b][L_b3]; auto __v232 = L_array[(L_a_Abi_i++)]; return (__a231 = __v232); }());
            }
         }
      }
   }
   (this->m_i |= 0x80);
   return L_a_Abi_i;
}
void g::a_i_v(int32_t L_n) {
   {
      switch (this->a_b) {
      case 3:
      {
         {
            if ((L_n == 2)) {
               (this->a_b = ((int8_t)(2)));
               return;
            }
            break;
         }
      }
      case 0:
      {
         {
            if ((L_n == 2)) {
               (this->a_b = ((int8_t)(2)));
               (this->g_b = ((int8_t)(0)));
            }
            if ((L_n == 1)) {
               (this->a_b = ((int8_t)(1)));
               return;
            }
            break;
         }
      }
      case 1:
      {
         {
            if ((L_n == 0)) {
               (this->a_b = ((int8_t)(0)));
               this->b__v();
               return;
            }
            break;
         }
      }
      case 2:
      {
         {
            if ((L_n == 1)) {
               (this->a_b = ((int8_t)(1)));
            }
            if ((L_n == 3)) {
               (this->a_b = ((int8_t)(3)));
               break;
            }
            break;
         }
      }
      }
   }
}
void g::b__v() {
   (this->g_b = ((int8_t)((-1))));
   for (int32_t L_i = 0; (L_i < this->a_AAb.length()); (++L_i)) {
      {
         Arr<int8_t> L_array{};
         {
            switch (((L_array = this->a_AAb[L_i]))[0]) {
            case 6:
            {
               {
                  (L_array[3] = L_array[1]);
                  (L_array[4] = L_array[2]);
                  break;
               }
            }
            case 16:
            {
               {
                  (L_array[15] = L_array[11]);
                  (L_array[16] = L_array[12]);
                  (L_array[17] = L_array[13]);
                  (L_array[18] = L_array[14]);
                  break;
               }
            }
            case 17:
            {
               {
                  (L_array[11] = L_array[7]);
                  (L_array[12] = L_array[8]);
                  (L_array[13] = L_array[9]);
                  (L_array[14] = L_array[10]);
                  break;
               }
            }
            }
         }
      }
   }
}
void g::a_GraphicsDirectGraphicsd_v(JGraphics L_graphics, JDirectGraphics L_directGraphics, d* L_d) {
}
void g::a_Agc_v(Arr<g*> L_array, c* L_c) {
   int32_t L_n = jwrap32(jwint(L_c->g_i) - jwint(L_c->e_i));
   int32_t L_n2 = jwrap32(jwint(L_c->h_i) - jwint(L_c->f_i));
   int32_t L_n3 = (((L_n < L_n2)) ? (jshr(int32_t(L_n2),1)) : (jshr(int32_t(L_n),1)));
   for (int32_t L_i = 0; (L_i < L_array.length()); (++L_i)) {
      {
         g* L_g{};
         if ((((L_g = L_array[L_i]))->a_b != 1)) {
            L_g->a_d_v(j::a_d);
            j::a_d->c_d_v((d::__ci(),d::a_d));
            (d::__ci(),d::a_d)->a_ii_v(L_c->b_d->c_i, L_c->b_d->f_i);
            int32_t L_g_i = (d::__ci(),d::g_i);
            int32_t L_h_i = (d::__ci(),d::h_i);
            (d::__ci(),d::a_d)->a_ii_v(L_c->c_d->c_i, L_c->c_d->f_i);
            int32_t L_g_i2 = (d::__ci(),d::g_i);
            int32_t L_h_i2 = (d::__ci(),d::h_i);
            int32_t L_n4 = jwrap32(jwint(L_g->e_i) - jwint(L_n3));
            int32_t L_n5 = jwrap32(jwint(L_g->f_i) - jwint(L_n3));
            int32_t L_n6 = jwrap32(jwint(L_g->g_i) + jwint(L_n3));
            int32_t L_n7 = jwrap32(jwint(L_g->h_i) + jwint(L_n3));
            bool L_b{};
            g* L_g2{};
            if ((((L_b = (([&]() { auto __l233 = j::a_iiiiiiii_z(L_g_i, L_h_i, L_g_i2, L_h_i2, L_n4, L_n5, L_n6, L_n7); auto __r234 = j::a_iiiiii_z(L_g_i2, L_h_i2, L_n4, L_n5, L_n6, L_n7); return (bool)(__l233 | __r234); }())))) && (((L_g2 = L_g))->a_i < 2))) {
               (L_g2->a_Aj[L_g2->a_i] = static_cast<j*>(L_c));
               g* L_g3 = L_g2;
               (++L_g3->a_i);
            }
         }
      }
   }
}
bool g::a_AObjectiObject_z(Arr<Obj> L_array, int32_t L_n, Obj L_o) {
   for (int32_t L_i = 0; (L_i < L_n); (++L_i)) {
      {
         if ((jsame(L_array[L_i],L_o))) {
            return true;
         }
      }
   }
   return false;
}
void g::a_Ag_v(Arr<g*> L_a_Ag) {
   (g::a_Ag = L_a_Ag);
   for (int32_t L_i = 0; (L_i < L_a_Ag.length()); (++L_i)) {
      {
         g* L_g{};
         if ((((L_g = L_a_Ag[L_i]))->d_b == 0)) {
            for (int32_t L_j = 0; (L_j < L_g->a_i); (++L_j)) {
               {
                  j* L_k = L_g->a_Aj[L_j];
                  if ((!g::a_AObjectiObject_z(jarr_obj(L_g->b_Aj), L_g->b_i, Obj(L_k)))) {
                     (g::c_Aj[L_j] = L_k);
                  }
               }
            }
         } else {
            for (int32_t L_l = 0; (L_l < L_g->b_i); (++L_l)) {
               {
                  j* L_m = L_g->b_Aj[L_l];
                  if ((!g::a_AObjectiObject_z(jarr_obj(L_g->a_Aj), L_g->a_i, Obj(L_m)))) {
                     (g::c_Aj[L_l] = L_m);
                  }
               }
            }
         }
         for (int32_t L_n = 0; (L_n < g::c_Aj.length()); (++L_n)) {
            {
               if (((g::c_Aj[L_n] != nullptr) && (((L_g->a_s <= (-1)) || ([&]() { auto __l235 = g::c_Aj[L_n]->a__s(); auto __r236 = L_g->a_s; return (__l235 == __r236); }()))))) {
                  L_g->a_i_v(2);
               }
            }
         }
         for (int32_t L_n2 = 0; (L_n2 < L_g->a_Aj.length()); (++L_n2)) {
            {
               (L_g->b_Aj[L_n2] = L_g->a_Aj[L_n2]);
               (L_g->a_Aj[L_n2] = nullptr);
               (g::c_Aj[L_n2] = nullptr);
            }
         }
         (L_g->b_i = L_g->a_i);
         (L_g->a_i = 0);
      }
   }
   for (int32_t L_n3 = 0; (L_n3 < L_a_Ag.length()); (++L_n3)) {
      {
         bool L_b{};
         do {
            {
               g* L_g2{};
               if ((((L_g2 = L_a_Ag[L_n3]))->a_j_z((m::__ci(),m::a_j)) && (L_g2->a_b == 2))) {
                  g* L_g3 = L_g2;
                  Arr<int8_t> L_array = L_g2->a_AAb[L_g2->g_b];
                  g* L_g4 = L_g3;
                  bool L_b2 = false;
                  {
                  {
                     {
                        switch (L_array[0]) {
                        case 1:
                        {
                           {
                              j* L_a_s_j{};
                              if ((((L_a_s_j = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)))) != nullptr)) {
                                 r* L_r = jdown<r>(L_a_s_j);
                                 for (int32_t L_n4 = 0; (L_n4 < L_r->a_As.length()); (++L_n4)) {
                                    {
                                       int16_t L_n5 = L_r->a_As[L_n4];
                                       int16_t L_n6 = ((int16_t)((-1)));
                                       int16_t L_n7 = ((int16_t)(0));
                                       {
                                          switch (L_n5) {
                                          case 118:
                                          {
                                             {
                                                (L_n6 = ((int16_t)(485)));
                                                (L_n7 = ((int16_t)(9999)));
                                                break;
                                             }
                                          }
                                          case 334:
                                          {
                                             {
                                                (L_n6 = ((int16_t)(474)));
                                                (L_n7 = ((int16_t)(750)));
                                                break;
                                             }
                                          }
                                          case 342:
                                          {
                                             {
                                                (L_n6 = ((int16_t)(480)));
                                                (L_n7 = ((int16_t)(9999)));
                                                break;
                                             }
                                          }
                                          }
                                       }
                                       if ((L_n6 > (-1))) {
                                          (L_r->b_As[L_n4] = L_n6);
                                          (L_r->a_As[L_n4] = L_n7);
                                       }
                                    }
                                 }
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 0:
                        {
                           {
                              int16_t L_n8 = (m::__ci(),m::a_As)[j::a_Abi_s(L_array, 1)];
                              if ((!(m::__ci(), m::a_i_z(13)))) {
                                 (m::__ci(), m::a_i_v(((int32_t)(L_n8))));
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 25:
                        {
                           {
                              ((m::__ci(),m::h_i) = L_g4->b_d->c_i);
                              ((m::__ci(),m::i_i) = L_g4->b_d->f_i);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 26:
                        {
                           {
                              j* L_a_s_j2{};
                              if ((((L_a_s_j2 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1))))->c_b == 4)) {
                                 c* L_c2{};
                                 c* L_c = (L_c2 = jdown<c>(L_a_s_j2));
                                 (L_c->f_f += j::a_Abi_s(L_array, 3));
                                 c* L_c3 = L_c2;
                                 (L_c3->g_f += j::a_Abi_s(L_array, 5));
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 27:
                        {
                           {
                              j* L_a_s_j3{};
                              if ((((L_a_s_j3 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1))))->c_b == 4)) {
                                 c* L_c5{};
                                 c* L_c4 = (L_c5 = jdown<c>(L_a_s_j3));
                                 (L_c4->d_f += j::a_Abi_s(L_array, 3));
                                 c* L_c6 = L_c5;
                                 (L_c6->e_f += j::a_Abi_s(L_array, 5));
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 28:
                        {
                           {
                              j* L_a_s_j4{};
                              if ((((L_a_s_j4 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1))))->c_b == 4)) {
                                 c* L_c8{};
                                 c* L_c7 = (L_c8 = jdown<c>(L_a_s_j4));
                                 (L_c7->a_f += j::a_Abi_s(L_array, 3));
                                 c* L_c9 = L_c8;
                                 (L_c9->b_f += j::a_Abi_s(L_array, 5));
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 3:
                        {
                           {
                              g::a_Ag[L_array[1]]->a_i_v(0);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 2:
                        {
                           {
                              g::a_Ag[L_array[1]]->a_i_v(1);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 4:
                        {
                           {
                              g::a_Ag[L_array[1]]->a_i_v(2);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 5:
                        {
                           {
                              g::a_Ag[L_array[1]]->a_i_v(3);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 24:
                        {
                           {
                              if ((!([&]() -> decltype(auto) { auto __p237 = L_g4->b_Aj; auto __p238 = L_g4->b_i; auto __p239 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)); return g::a_AObjectiObject_z(jarr_obj(__p237), __p238, Obj(__p239)); }()))) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              break;
                           }
                        }
                        case 6:
                        {
                           {
                              int16_t L_a_Abi_s{};
                              if ((((L_a_Abi_s = j::a_Abi_s(L_array, 3))) < 0)) {
                                 (L_array[3] = L_array[1]);
                                 (L_array[4] = L_array[2]);
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              int16_t L_n9 = ((int16_t)((jwrap32(jwint(L_a_Abi_s) - jwint((o::__ci(),o::a_i))))));
                              Arr<int8_t> L_array2 = L_array;
                              int16_t L_n10 = L_n9;
                              Arr<int8_t> L_array3 = L_array2;
                              (L_array2[3] = ((int8_t)((jshr(int32_t(L_n10),8)))));
                              (L_array3[4] = ((int8_t)(L_n10)));
                              break;
                           }
                        }
                        case 30:
                        {
                           {
                              (j::a_j = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 31:
                        {
                           {
                              ((m::__ci(),m::c_z) = ((L_array[1] == 1)));
                              (j::p_i = ((int32_t)(j::a_Abi_s(L_array, 2))));
                              (j::q_i = ((int32_t)(j::a_Abi_s(L_array, 4))));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 32:
                        {
                           {
                              ((m::__ci(),m::c_z) = false);
                              (j::p_i = 90);
                              (j::q_i = 140);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 19:
                        {
                           {
                              int16_t L_a_Abi_s2 = j::a_Abi_s(L_array, 1);
                              int16_t L_a_Abi_s3 = j::a_Abi_s(L_array, 3);
                              j* L_a__j = L_g4->a__j();
                              j* L_a_s_j5{};
                              if ((((L_a_s_j5 = j::b_j->a_s_j(L_a_Abi_s2))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              j* L_a_s_j6{};
                              if ((((L_a_s_j6 = L_a__j->a_s_j(L_a_Abi_s3))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              L_a_s_j5->b_j_v(L_a_s_j6);
                              L_a_s_j5->i__v();
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 20:
                        {
                           {
                              j* L_a_s_j7{};
                              if ((((L_a_s_j7 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              L_a_s_j7->i__v();
                              L_a_s_j7->b_j_v(j::b_j);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 18:
                        {
                           {
                              j* L_a_s_j8{};
                              if ((((L_a_s_j8 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              int16_t L_a_Abi_s4{};
                              if ((((L_a_Abi_s4 = j::a_Abi_s(L_array, 3))) < 0)) {
                                 (L_a_s_j8->c_d->c_i = j::b_Abi_i(L_array, 5));
                                 (L_a_s_j8->c_d->f_i = j::b_Abi_i(L_array, 9));
                              } else {
                                 j* L_a_s_j9{};
                                 if ((((L_a_s_j9 = L_g4->a__j()->a_s_j(L_a_Abi_s4))) != nullptr)) {
                                    L_a_s_j9->a_d_v(j::a_d);
                                    int32_t L_c_i = j::a_d->c_i;
                                    int32_t L_f_i = j::a_d->f_i;
                                    (L_a_s_j8->c_d->c_i = 0);
                                    (L_a_s_j8->c_d->f_i = 0);
                                    (L_a_s_j8->f_z = true);
                                    L_a_s_j8->a_d_v(j::a_d);
                                    j::a_d->c_d_v((d::__ci(),d::a_d));
                                    (d::__ci(),d::a_d)->a_ii_v(L_c_i, L_f_i);
                                    (L_a_s_j8->c_d->c_i = (d::__ci(),d::g_i));
                                    (L_a_s_j8->c_d->f_i = (d::__ci(),d::h_i));
                                 }
                              }
                              L_a_s_j8->h__v();
                              L_a_s_j8->i__v();
                              L_a_s_j8->a_d_v(L_a_s_j8->b_d);
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 16:
                        {
                           {
                              j* L_a_s_j10{};
                              if ((((L_a_s_j10 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              int32_t L_b_Abi_i = j::b_Abi_i(L_array, 15);
                              int32_t L_a_i = (o::__ci(),o::a_i);
                              if ((jwrap32(jwint(L_b_Abi_i) - jwint(L_a_i)) <= 0)) {
                                 (L_array[15] = L_array[11]);
                                 (L_array[16] = L_array[12]);
                                 (L_array[17] = L_array[13]);
                                 (L_array[18] = L_array[14]);
                                 (L_a_i = L_b_Abi_i);
                              }
                              d* L_c_d = L_a_s_j10->c_d;
                              (L_c_d->c_i += ([&]() { auto __l240 = j::b_Abi_i(L_array, 3); auto __r241 = L_a_i; return jwrap32(jwint(__l240) * jwint(__r241)); }()));
                              d* L_c_d2 = L_a_s_j10->c_d;
                              (L_c_d2->f_i += ([&]() { auto __l242 = j::b_Abi_i(L_array, 7); auto __r243 = L_a_i; return jwrap32(jwint(__l242) * jwint(__r243)); }()));
                              L_a_s_j10->h__v();
                              L_a_s_j10->i__v();
                              int32_t L_n11{};
                              if ((((L_n11 = jwrap32(jwint(L_b_Abi_i) - jwint(L_a_i)))) <= 0)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              g::a_Abii_v(L_array, 15, L_n11);
                              break;
                           }
                        }
                        case 17:
                        {
                           {
                              j* L_a_s_j11{};
                              if ((((L_a_s_j11 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              int32_t L_b_Abi_i2 = j::b_Abi_i(L_array, 11);
                              int32_t L_b_Abi_i3 = j::b_Abi_i(L_array, 7);
                              int32_t L_a_i2 = (o::__ci(),o::a_i);
                              if ((L_b_Abi_i2 == L_b_Abi_i3)) {
                                 g::a_Abii_v(L_array, 15, L_a_s_j11->c_d->a_i);
                                 g::a_Abii_v(L_array, 19, L_a_s_j11->c_d->b_i);
                                 g::a_Abii_v(L_array, 23, L_a_s_j11->c_d->d_i);
                                 g::a_Abii_v(L_array, 27, L_a_s_j11->c_d->e_i);
                              }
                              if ((jwrap32(jwint(L_b_Abi_i2) - jwint(L_a_i2)) <= 0)) {
                                 (L_array[11] = L_array[7]);
                                 (L_array[12] = L_array[8]);
                                 (L_array[13] = L_array[9]);
                                 (L_array[14] = L_array[10]);
                                 (L_b_Abi_i2 = 0);
                              }
                              (d::__ci(),d::a_d)->a_f_v((([&]() { auto __l246 = ([&]() { auto __l244 = j::b_Abi_i(L_array, 3); auto __r245 = ((int64_t)((jwrap32(jwint(L_b_Abi_i3) - jwint(L_b_Abi_i2))))); return jwrap64(jwlong(__l244) * jwlong(__r245)); }()); auto __r247 = L_b_Abi_i3; return jdiv(int64_t(__l246),int64_t(__r247)); }()) / 65536.0f));
                              ((d::__ci(),d::a_d)->c_i = 0);
                              ((d::__ci(),d::a_d)->f_i = 0);
                              (L_a_s_j11->c_d->a_i = j::b_Abi_i(L_array, 15));
                              (L_a_s_j11->c_d->b_i = j::b_Abi_i(L_array, 19));
                              (L_a_s_j11->c_d->d_i = j::b_Abi_i(L_array, 23));
                              (L_a_s_j11->c_d->e_i = j::b_Abi_i(L_array, 27));
                              L_a_s_j11->c_d->b_d_v((d::__ci(),d::a_d));
                              L_a_s_j11->h__v();
                              L_a_s_j11->i__v();
                              int32_t L_n12{};
                              if ((((L_n12 = jwrap32(jwint(L_b_Abi_i2) - jwint(L_a_i2)))) <= 0)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              g::a_Abii_v(L_array, 11, L_n12);
                              break;
                           }
                        }
                        case 29:
                        {
                           {
                              j* L_a_s_j12{};
                              if ((((L_a_s_j12 = L_g4->a__j()->a_s_j(j::a_Abi_s(L_array, 1)))) == nullptr)) {
                                 (L_b2 = true);
                                 goto Label_2887_brk;
                              }
                              int32_t L_b_Abi_i4 = j::b_Abi_i(L_array, 3);
                              int32_t L_b_Abi_i5 = j::b_Abi_i(L_array, 7);
                              if ((((L_b_Abi_i4 & 0x1)) > 0)) {
                                 j* L_j2 = L_a_s_j12;
                                 (L_j2->m_i &= (int32_t)0xFFFFFFE0U);
                                 j* L_j3 = L_a_s_j12;
                                 (L_j3->m_i |= ((L_b_Abi_i5 & 0x1F)));
                                 (L_a_s_j12->b_b = ((int8_t)((jwrap32(jwint(((L_a_s_j12->m_i & 0x1F))) - jwint(16))))));
                              }
                              if ((((L_b_Abi_i4 & 0x20)) > 0)) {
                                 j* L_j4 = L_a_s_j12;
                                 (L_j4->m_i &= (int32_t)0xFFFFFFDFU);
                                 j* L_j5 = L_a_s_j12;
                                 (L_j5->m_i |= ((L_b_Abi_i5 & 0x20)));
                              }
                              if ((((L_b_Abi_i4 & 0x80)) > 0)) {
                                 j* L_j6 = L_a_s_j12;
                                 (L_j6->m_i &= (int32_t)0xFFFFFF7FU);
                                 j* L_j7 = L_a_s_j12;
                                 (L_j7->m_i |= ((L_b_Abi_i5 & 0x80)));
                                 r* L_r2{};
                                 if (((L_a_s_j12->a__b() == 5) && (((L_r2 = jdown<r>(L_a_s_j12)))->a_As[0] == 358))) {
                                    L_r2->a_d_v(j::a_d);
                                    (m::__ci(),m::h_n)->a_iiiiiiiiiii_v(24, jwrap32(jwint(j::a_d->c_i) + jwint((jwrap32(jwint(L_r2->e_i) + jwint(3932160))))), jwrap32(jwint(j::a_d->f_i) + jwint((jwrap32(jwint(L_r2->f_i) + jwint(3932160))))), jwrap32(jwint(j::a_d->c_i) + jwint((jwrap32(jwint(L_r2->g_i) - jwint(3932160))))), jwrap32(jwint(j::a_d->f_i) + jwint((jwrap32(jwint(L_r2->h_i) - jwint(3932160))))), 840, 0, 0, 360, 2040, 510);
                                 }
                              }
                              if ((((L_b_Abi_i4 & 0x100)) > 0)) {
                                 r* L_r3 = jdown<r>(L_a_s_j12);
                                 (L_r3->m_i &= (int32_t)0xFFFFFEFFU);
                                 r* L_r4 = jdown<r>(L_a_s_j12);
                                 (L_r4->m_i |= ((L_b_Abi_i5 & 0x100)));
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 23:
                        {
                           {
                              if ((L_g4->e_b == 1)) {
                                 (L_g4->a_b = ((int8_t)(0)));
                                 break;
                              }
                              (L_g4->a_b = ((int8_t)(1)));
                              break;
                           }
                        }
                        case 21:
                        {
                           {
                              (L_g4->g_b = ((int8_t)((jwrap32(jwint(L_array[1]) - jwint(2))))));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 22:
                        {
                           {
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 7:
                        {
                           {
                              if ((L_array[1] == 1)) {
                                 ([&]() -> decltype(auto) { auto __p248 = L_array[2]; auto __p249 = g::a_Abi_f(L_array, 3); return g::a_bf_v(__p248, __p249); }());
                              }
                              if ((L_array[1] == 2)) {
                                 ([&]() -> decltype(auto) { auto& __a250 = g::a_Ai[L_array[2]]; auto __v251 = g::c_Abi_i(L_array, 3); return (__a250 = __v251); }());
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 8:
                        {
                           {
                              if ((L_array[1] == 1)) {
                                 ([&]() -> decltype(auto) { auto __p254 = L_array[2]; auto __p255 = ([&]() { auto __l252 = g::a_b_f(L_array[2]); auto __r253 = g::a_Abi_f(L_array, 3); return (__l252 + __r253); }()); return g::a_bf_v(__p254, __p255); }());
                              }
                              if ((L_array[1] == 2)) {
                                 Arr<int32_t> L_a_Ai = g::a_Ai;
                                 int8_t L_b3 = L_array[2];
                                 ([&]() -> decltype(auto) { auto& __a256 = L_a_Ai[L_b3]; auto __v257 = g::c_Abi_i(L_array, 3); return (__a256 += __v257); }());
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 9:
                        {
                           {
                              if ((L_array[1] == 1)) {
                                 ([&]() -> decltype(auto) { auto __p260 = L_array[2]; auto __p261 = ([&]() { auto __l258 = g::a_b_f(L_array[2]); auto __r259 = g::a_Abi_f(L_array, 3); return (__l258 - __r259); }()); return g::a_bf_v(__p260, __p261); }());
                              }
                              if ((L_array[1] == 2)) {
                                 Arr<int32_t> L_a_Ai2 = g::a_Ai;
                                 int8_t L_b4 = L_array[2];
                                 ([&]() -> decltype(auto) { auto& __a262 = L_a_Ai2[L_b4]; auto __v263 = g::c_Abi_i(L_array, 3); return (__a262 -= __v263); }());
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 10:
                        {
                           {
                              if ((L_array[1] == 1)) {
                                 ([&]() -> decltype(auto) { auto __p266 = L_array[2]; auto __p267 = ([&]() { auto __l264 = g::a_b_f(L_array[2]); auto __r265 = g::a_Abi_f(L_array, 3); return (__l264 * __r265); }()); return g::a_bf_v(__p266, __p267); }());
                              }
                              if ((L_array[1] == 2)) {
                                 Arr<int32_t> L_a_Ai3 = g::a_Ai;
                                 int8_t L_b5 = L_array[2];
                                 ([&]() -> decltype(auto) { auto& __a268 = L_a_Ai3[L_b5]; auto __v269 = g::c_Abi_i(L_array, 3); return (__a268 *= __v269); }());
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 11:
                        {
                           {
                              if ((L_array[1] == 1)) {
                                 ([&]() -> decltype(auto) { auto __p272 = L_array[2]; auto __p273 = ([&]() { auto __l270 = g::a_b_f(L_array[2]); auto __r271 = g::a_Abi_f(L_array, 3); return (__l270 / __r271); }()); return g::a_bf_v(__p272, __p273); }());
                              }
                              if ((L_array[1] == 2)) {
                                 Arr<int32_t> L_a_Ai4 = g::a_Ai;
                                 int8_t L_b6 = L_array[2];
                                 ([&]() -> decltype(auto) { auto& __a274 = L_a_Ai4[L_b6]; auto __v275 = g::c_Abi_i(L_array, 3); return (__a274 = (int32_t)jdiv(__a274,__v275)); }());
                              }
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 12:
                        {
                           {
                              if ((L_array[1] == 2)) {
                                 if (([&]() { auto __l276 = g::a_Ai[L_array[2]]; auto __r277 = g::c_Abi_i(L_array, 3); return (__l276 == __r277); }())) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              } else {
                                 if (((L_array[1] == 1) && ([&]() { auto __l278 = g::a_b_f(L_array[2]); auto __r279 = g::a_Abi_f(L_array, 3); return (__l278 == __r279); }()))) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              }
                              (L_g4->g_b = ((int8_t)((jwrap32(jwint(L_array[g::c_i]) - jwint(2))))));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 13:
                        {
                           {
                              if ((L_array[1] == 2)) {
                                 if (([&]() { auto __l280 = g::a_Ai[L_array[2]]; auto __r281 = g::c_Abi_i(L_array, 3); return (__l280 != __r281); }())) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              } else {
                                 if (((L_array[1] == 1) && ([&]() { auto __l282 = g::a_b_f(L_array[2]); auto __r283 = g::a_Abi_f(L_array, 3); return (__l282 != __r283); }()))) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              }
                              (L_g4->g_b = ((int8_t)((jwrap32(jwint(L_array[g::c_i]) - jwint(2))))));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 14:
                        {
                           {
                              if ((L_array[1] == 2)) {
                                 if (([&]() { auto __l284 = g::a_Ai[L_array[2]]; auto __r285 = g::c_Abi_i(L_array, 3); return (__l284 < __r285); }())) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              } else {
                                 if (((L_array[1] == 1) && ([&]() { auto __l286 = g::a_b_f(L_array[2]); auto __r287 = g::a_Abi_f(L_array, 3); return (__l286 < __r287); }()))) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              }
                              (L_g4->g_b = ((int8_t)((jwrap32(jwint(L_array[g::c_i]) - jwint(2))))));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        case 15:
                        {
                           {
                              if ((L_array[1] == 2)) {
                                 if (([&]() { auto __l288 = g::a_Ai[L_array[2]]; auto __r289 = g::c_Abi_i(L_array, 3); return (__l288 > __r289); }())) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              } else {
                                 if (((L_array[1] == 1) && ([&]() { auto __l290 = g::a_b_f(L_array[2]); auto __r291 = g::a_Abi_f(L_array, 3); return (__l290 > __r291); }()))) {
                                    (L_b2 = true);
                                    goto Label_2887_brk;
                                 }
                              }
                              (L_g4->g_b = ((int8_t)((jwrap32(jwint(L_array[g::c_i]) - jwint(2))))));
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        default:
                        {
                           {
                              (L_b2 = true);
                              goto Label_2887_brk;
                           }
                        }
                        }
                     }
                     (L_b2 = false);
                  }
                  }
                  Label_2887_brk:;
                  if (L_b2) {
                     if ((L_g2->g_b < (-1))) {
                        (L_g2->g_b = ((int8_t)((-1))));
                     }
                     g* L_g5 = L_g2;
                     (++L_g5->g_b);
                     if ((L_g2->g_b >= L_g2->f_b)) {
                        if ((L_g2->e_b == 1)) {
                           (L_g2->a_b = ((int8_t)(0)));
                           L_g2->b__v();
                        } else {
                           (L_g2->a_b = ((int8_t)(1)));
                        }
                        (L_b = false);
                        continue;
                     }
                     (L_b = true);
                     continue;
                  }
               }
               (L_b = false);
            }
         } while (L_b);
      }
   }
}
int32_t g::c_Abi_i(Arr<int8_t> L_array, int32_t L_n) {
   (L_n = ((int32_t)(L_array[3])));
   int32_t L_b_Abi_i = 0;
   (g::c_i = 4);
   {
      switch (L_n) {
      case 32:
      {
         {
            (g::c_i += 4);
            (L_b_Abi_i = j::b_Abi_i(L_array, 4));
            break;
         }
      }
      case 2:
      {
         {
            (++g::c_i);
            (L_b_Abi_i = g::a_Ai[L_array[4]]);
            break;
         }
      }
      }
   }
   return L_b_Abi_i;
}
float g::a_b_f(int8_t L_b) {
   return JFloat::intBitsToFloat(g::a_Ai[L_b]);
}
void g::a_bf_v(int8_t L_b, float L_value) {
   ([&]() -> decltype(auto) { auto& __a292 = g::a_Ai[L_b]; auto __v293 = JFloat::floatToIntBits(L_value); return (__a292 = __v293); }());
}
float g::a_Abi_f(Arr<int8_t> L_array, int32_t L_n) {
   (L_n = ((int32_t)(L_array[3])));
   float L_n2 = 0.0f;
   (g::c_i = 4);
   {
      switch (L_n) {
      case 16:
      {
         {
            (g::c_i += 4);
            Arr<int8_t> L_array2 = L_array;
            (L_n = 4);
            (L_array = L_array2);
            (L_n2 = JFloat::intBitsToFloat(((int32_t)(((jshl(int64_t(((jshl(int64_t(((jshl(int64_t((((int64_t)0x0LL | ((int64_t)(L_array[L_n]))))),8) | ((int64_t)(((L_array[jwrap32(jwint(L_n) + jwint(1))] & 0xFF))))))),8) | ((int64_t)(((L_array[jwrap32(jwint(L_n) + jwint(2))] & 0xFF))))))),8) | ((int64_t)(((L_array[jwrap32(jwint(L_n) + jwint(3))] & 0xFF))))))))));
            break;
         }
      }
      case 1:
      {
         {
            (++g::c_i);
            (L_n2 = g::a_b_f(L_array[4]));
            break;
         }
      }
      case 32:
      {
         {
            (g::c_i += 4);
            (L_n2 = ((float)(j::b_Abi_i(L_array, 4))));
            break;
         }
      }
      case 2:
      {
         {
            (++g::c_i);
            (L_n2 = ((float)(g::a_Ai[L_array[4]])));
            break;
         }
      }
      }
   }
   return L_n2;
}
void g::a_Abii_v(Arr<int8_t> L_array, int32_t L_n, int32_t L_n2) {
   (L_array[L_n] = ((int8_t)((jushr(int32_t(L_n2),24)))));
   (L_array[jwrap32(jwint(L_n) + jwint(1))] = ((int8_t)((jshr(int32_t(L_n2),16)))));
   (L_array[jwrap32(jwint(L_n) + jwint(2))] = ((int8_t)((jshr(int32_t(L_n2),8)))));
   (L_array[jwrap32(jwint(L_n) + jwint(3))] = ((int8_t)(L_n2)));
}
void h::__clinit() {
   __inited = true;
   e_Ai = newArr<int32_t>(4);
   f_Ai = Arr<int32_t>({3, 12, 48, 64, 128, 256, 1536, 2048, 4096});
   g_Ai = Arr<int32_t>({(-1), 7304, (-1), (-1), 1, 1, 1, 1, 16777215, 0, 0, 6710886, 0, 0, 6710886, 11171584});
   h_Ai = Arr<int32_t>({3, 12, 16, 32, 64, 128});
   i_Ai = Arr<int32_t>({(-1), 8, 2, 2, 2, 0, 0, (-1), (-1), (-1), 20, 12, 12, 2, 6, 1, 4456448, 6170113, 68, 10526880, 0, 10027008, 0});
}
h::h() {
   this->a_Vector = JVector::make();
   this->b_i = (-1);
   this->c_i = 0;
   this->a_i = 0;
   this->a_Ai = nullptr;
   this->b_Ai = nullptr;
   this->a_b = nullptr;
   this->d_i = (-1);
   this->e_i = 0;
   this->f_i = 0;
   this->g_i = 1;
   this->c_Ai = newArr<int32_t>(3);
   this->a_AString = newArr<JString>(3);
   this->d_Ai = newArr<int32_t>(3);
}
void h::a_f_v(f* L_var1) {
   int32_t L_var2 = this->a_Vector->size();
   this->a_Vector->insertElementAt(L_var1, L_var2);
   (L_var1->a_h = this);
   if (((this->b_i == (-1)) && this->a_i_z(L_var2))) {
      this->a_i_v(L_var2);
   }
}
void h::a__v() {
   this->a_Vector->removeAllElements();
   (this->c_i = 0);
   (this->b_i = (-1));
}
bool h::a_i_z(int32_t L_var1) {
   f* L_var2 = jcast<f*>(this->a_Vector->elementAt(L_var1));
   int32_t L_var3{};
   return (([&]() { auto __l294 = ((L_var3 = this->a_i_i(L_var1))); auto __r295 = this->c_i; return (__l294 >= __r295); }()) && ([&]() { auto __l300 = ([&]() { auto __l296 = L_var3; auto __r297 = L_var2->b__i(); return jwrap32(jwint(__l296) + jwint(__r297)); }()); auto __r301 = ([&]() { auto __l298 = this->c_i; auto __r299 = this->e__i(); return jwrap32(jwint(__l298) + jwint(__r299)); }()); return (__l300 <= __r301); }()));
}
int32_t h::a__i() {
   return this->b_i;
}
void h::a_i_v(int32_t L_var1) {
   if (([&]() { auto __l302 = L_var1; auto __r303 = this->a_Vector->size(); return (__l302 >= __r303); }())) {
      (L_var1 = jwrap32(jwint(this->a_Vector->size()) - jwint(1)));
   }
   if ((L_var1 != this->b_i)) {
      if (((L_var1 == (-1)) || (jcast<f*>(this->a_Vector->elementAt(L_var1)))->a__z())) {
         int32_t L_var2 = this->b_i;
         (this->b_i = L_var1);
         if ((L_var2 != (-1))) {
            this->a_Vector->elementAt(L_var2);
         }
         if ((L_var1 != (-1))) {
            this->a_Vector->elementAt(L_var1);
         }
         if ((this->b_i != (-1))) {
            (L_var2 = ([&]() { auto __l304 = ((L_var1 = this->a_i_i(this->b_i))); auto __r305 = (jcast<f*>(this->a_Vector->elementAt(this->b_i)))->b__i(); return jwrap32(jwint(__l304) + jwint(__r305)); }()));
            int32_t L_var3 = this->e__i();
            if ((L_var1 < this->c_i)) {
               (this->c_i = L_var1);
               return;
            }
            if ((L_var2 > jwrap32(jwint(this->c_i) + jwint(L_var3)))) {
               (this->c_i = jwrap32(jwint(L_var2) - jwint(L_var3)));
            }
         }
      }
   }
}
f* h::a__f() {
   f* L_var1{};
   return (((((L_var1 = ((this->b_i != (-1)) ? jcast<f*>(this->a_Vector->elementAt(this->b_i)) : static_cast<f*>(nullptr)))) != nullptr) && L_var1->a_z) ? L_var1 : static_cast<f*>(nullptr));
}
void h::a_Stringii_v(JString L_var1, int32_t L_var2, int32_t L_var3) {
   (L_var2 = (this->c_i_i(0) | 256));
   ([&]() -> decltype(auto) { auto& __a311 = this->a_b; auto __v312 = (((L_var1 != nullptr) && (L_var1.length() > 0)) ? ([&]() -> decltype(auto) { auto __p306 = L_var1; auto __p307 = J_Integer_MAX_VALUE; auto __p308 = this->c_i_i(13); auto __p309 = L_var2; auto __p310 = (-1); return (b::__ci(), new b(__p306, __p307, __p308, __p309, __p310)); }()) : static_cast<b*>(nullptr)); return (__a311 = __v312); }());
   (this->d_i = (-1));
   (this->f_i = 0);
}
void h::a_iStringiiz_v(int32_t L_var1, JString L_var2, int32_t L_var3, int32_t L_var4, bool L_var5) {
   (this->c_Ai[L_var1] = (1114112 | (((int16_t)(L_var4)) & char16_t(u'￿'))));
   (this->a_AString[L_var1] = L_var2);
   (this->d_Ai[L_var1] = 0);
}
void h::a_iStringi_v(int32_t L_var1, JString L_var2, int32_t L_var3) {
   if ((((this->c_Ai[0] & 65536)) == 65536)) {
      (this->a_AString[0] = L_var2);
      (this->d_Ai[0] = 0);
   }
}
void h::b_i_v(int32_t L_var1) {
   (this->c_Ai[L_var1] = 0);
   (this->a_AString[L_var1] = nullptr);
   (this->d_Ai[L_var1] = 0);
}
void h::b__v() {
   for (int32_t L_var1 = 0; (L_var1 < 3); (L_var1++)) {
      {
         bool L_var2 = (((int16_t)(this->c_Ai[L_var1])) == (-2));
         f* L_var3 = this->a__f();
         if ((((((this->c_Ai[L_var1] & 65536)) != 0) && (((this->c_Ai[L_var1] & 1048576)) != 0)) && (((!L_var2) || (L_var3 != nullptr))))) {
            (o::__ci(), o::a_iStringi_v(jwrap32(jwint(L_var1) + jwint(0)), this->a_AString[L_var1], this->d_Ai[L_var1]));
         } else {
            (o::__ci(), o::a_iStringi_v(jwrap32(jwint(L_var1) + jwint(0)), nullptr, 0));
         }
      }
   }
}
int32_t h::a_i_i(int32_t L_var1) {
   int32_t L_var2 = 0;
   for (int32_t L_var3 = 0; (L_var3 < L_var1); (L_var3++)) {
      {
         (L_var2 += ([&]() { auto __l313 = (jcast<f*>(this->a_Vector->elementAt(L_var3)))->b__i(); auto __r314 = this->c_i_i(19); return jwrap32(jwint(__l313) + jwint(__r314)); }()));
      }
   }
   return L_var2;
}
int32_t h::a_fi_i(f* L_var0, int32_t L_var1) {
   int32_t L_var2{};
   if ((((L_var2 = L_var0->a_i_i(6))) == 512)) {
      return ([&]() { auto __l315 = L_var1; auto __r316 = L_var0->a__i(); return jwrap32(jwint(__l315) - jwint(__r316)); }());
   } else {
      return ((L_var2 == 1024) ? jshr(int32_t(([&]() { auto __l317 = L_var1; auto __r318 = L_var0->a__i(); return jwrap32(jwint(__l317) - jwint(__r318)); }())),1) : 0);
   }
}
int32_t h::c__i() {
   int32_t L_var1{};
   return ((((L_var1 = this->c_i_i(11))) > 0) ? L_var1 : ([&]() { auto __l319 = (o::__ci(), o::e__i()); auto __r320 = (((o::__ci(), o::a__z()) ? (o::__ci(), o::d__i()) : 0)); return jwrap32(jwint(__l319) - jwint(__r320)); }()));
}
int32_t h::b__i() {
   return ([&]() { auto __l323 = ([&]() { auto __l321 = this->c__i(); auto __r322 = this->c_i_i(15); return jwrap32(jwint(__l321) - jwint(__r322)); }()); auto __r324 = this->c_i_i(16); return jwrap32(jwint(__l323) - jwint(__r324)); }());
}
int32_t h::d__i() {
   return ((this->a_Vector->size() > 0) ? ([&]() { auto __l325 = this->a_i_i(jwrap32(jwint(this->a_Vector->size()) - jwint(1))); auto __r326 = (jcast<f*>(this->a_Vector->lastElement()))->b__i(); return jwrap32(jwint(__l325) + jwint(__r326)); }()) : 0);
}
int32_t h::e__i() {
   int32_t L_var1 = this->b_i_i(5);
   return (([&]() { auto __l327 = this->d__i(); auto __r328 = L_var1; return (__l327 > __r328); }()) ? ([&]() { auto __l331 = ([&]() { auto __l329 = L_var1; auto __r330 = this->b_i_i(6); return jwrap32(jwint(__l329) - jwint(__r330)); }()); auto __r332 = this->b_i_i(7); return jwrap32(jwint(__l331) - jwint(__r332)); }()) : L_var1);
}
int32_t h::b_i_i(int32_t L_var1) {
   {
      int32_t L_var2{};
      switch (L_var1) {
      case 1:
      {
         L_var2 = ([&]() { auto __l333 = (o::__ci(),o::c_i); auto __r334 = (((o::__ci(), o::b__z()) ? (o::__ci(), o::c__i()) : 0)); return jwrap32(jwint(__l333) - jwint(__r334)); }());
         if ((this->c_i_i(3) == 32)) {
            return ([&]() -> decltype(auto) { auto __p341 = ([&]() { auto __l339 = ([&]() { auto __l337 = ([&]() { auto __l335 = this->b_i_i(2); auto __r336 = this->d__i(); return jwrap32(jwint(__l335) + jwint(__r336)); }()); auto __r338 = this->c_i_i(17); return jwrap32(jwint(__l337) + jwint(__r338)); }()); auto __r340 = this->c_i_i(18); return jwrap32(jwint(__l339) + jwint(__r340)); }()); auto __p342 = L_var2; return jmath_min<int32_t>(__p341, __p342); }());
         } else {
            if ((((L_var1 = this->c_i_i(12))) > 0)) {
               return L_var1;
            }
            return L_var2;
         }
      }
      case 2:
      {
         return ([&]() { auto __l347 = ([&]() { auto __l345 = ([&]() -> decltype(auto) { auto __p343 = ((this->a_b != nullptr) ? this->a_b->c_i : 0); auto __p344 = ((this->d_i != (-1)) ? (o::__ci(), o::a_ii_i(this->d_i, 1)) : 0); return jmath_max<int32_t>(__p343, __p344); }()); auto __r346 = this->c_i_i(6); return jwrap32(jwint(__l345) + jwint(__r346)); }()); auto __r348 = this->c_i_i(7); return jwrap32(jwint(__l347) + jwint(__r348)); }());
      }
      case 3:
      default:
      {
         return 0;
      }
      case 4:
      {
         return ([&]() { auto __l349 = this->b_i_i(1); auto __r350 = this->b_i_i(2); return jwrap32(jwint(__l349) - jwint(__r350)); }());
      }
      case 5:
      {
         return ([&]() { auto __l353 = ([&]() { auto __l351 = this->b_i_i(4); auto __r352 = this->c_i_i(17); return jwrap32(jwint(__l351) - jwint(__r352)); }()); auto __r354 = this->c_i_i(18); return jwrap32(jwint(__l353) - jwint(__r354)); }());
      }
      case 6:
      {
         return jwrap32(jwint(1) + jwint((o::__ci(), o::a_ii_i(151, 1))));
      }
      case 7:
      {
         return jwrap32(jwint(1) + jwint((o::__ci(), o::a_ii_i(150, 1))));
      }
      }
   }
}
void h::c_i_v(int32_t L_var1) {
   f* L_var2 = this->a__f();
   int32_t L_var3 = 0;
   {
      switch (L_var1) {
      case 1:
      {
         if ((this->a_Vector->size() != 0)) {
            if ((this->b_i == (-1))) {
               (L_var1 = (-1));
               for (int32_t L_var14 = 0; ([&]() { auto __l355 = L_var14; auto __r356 = this->a_Vector->size(); return (__l355 < __r356); }()); (L_var14++)) {
                  {
                     f* L_var20 = jcast<f*>(this->a_Vector->elementAt(L_var14));
                     int32_t L_var24{};
                     int32_t L_var28 = ([&]() { auto __l357 = ((L_var24 = this->a_i_i(L_var14))); auto __r358 = L_var20->b__i(); return jwrap32(jwint(__l357) + jwint(__r358)); }());
                     if ((L_var24 >= this->c_i)) {
                        break;
                     }
                     if ((L_var20->a__z() && ([&]() { auto __l361 = L_var28; auto __r362 = ([&]() { auto __l359 = this->c_i; auto __r360 = this->c_i_i(14); return jwrap32(jwint(__l359) - jwint(__r360)); }()); return (__l361 > __r362); }()))) {
                        (L_var1 = L_var14);
                     }
                  }
               }
            } else {
               int32_t L_var30 = this->b_i;
               h* L_var6 = this;
               (L_var3 = jwrap32(jwint(L_var30) - jwint(1)));
               int32_t L_var32{};
               while (true) {
                  {
                     if ((L_var3 < 0)) {
                        (L_var32 = (-1));
                        break;
                     }
                     if ((jcast<f*>(L_var6->a_Vector->elementAt(L_var3)))->a__z()) {
                        (L_var32 = L_var3);
                        break;
                     }
                     (L_var3--);
                  }
               }
               (L_var1 = L_var32);
               if (((L_var32 != (-1)) && ([&]() { auto __l367 = ([&]() { auto __l363 = this->a_i_i(L_var1); auto __r364 = (jcast<f*>(this->a_Vector->elementAt(L_var1)))->b__i(); return jwrap32(jwint(__l363) + jwint(__r364)); }()); auto __r368 = ([&]() { auto __l365 = this->c_i; auto __r366 = this->c_i_i(14); return jwrap32(jwint(__l365) - jwint(__r366)); }()); return (__l367 < __r368); }()))) {
                  (L_var1 = (-1));
               }
            }
            if ((L_var1 == (-1))) {
               if (((this->c_i_i(5) == 128) && (this->c_i <= 0))) {
                  h* L_var29 = this;
                  int32_t L_var31 = this->d__i();
                  (L_var3 = this->e__i());
                  (this->c_i = jwrap32(jwint(L_var31) - jwint(L_var3)));
                  if (([&]() { auto __l369 = L_var31; auto __r370 = this->b_i_i(5); return (__l369 < __r370); }())) {
                     (this->c_i = 0);
                  }
                  int32_t L_var25 = jwrap32(jwint(this->a_Vector->size()) - jwint(1));
                  while (true) {
                     {
                        if ((L_var25 <= 0)) {
                           return;
                        }
                        if ((!L_var29->a_i_z(L_var25))) {
                           L_var29->a_i_v((-1));
                           break;
                        }
                        if ((jcast<f*>(L_var29->a_Vector->elementAt(L_var25)))->a__z()) {
                           L_var29->a_i_v(L_var25);
                           break;
                        }
                        (L_var25--);
                     }
                  }
               } else {
                  ([&]() -> decltype(auto) { auto& __a373 = this->c_i; auto __v374 = ([&]() { auto __l371 = this->c_i; auto __r372 = this->c_i_i(14); return jwrap32(jwint(__l371) - jwint(__r372)); }()); return (__a373 = __v374); }());
                  if ((this->c_i < 0)) {
                     (this->c_i = 0);
                  }
                  if (((this->b_i != (-1)) && (!this->a_i_z(this->b_i)))) {
                     this->a_i_v((-1));
                     return;
                  }
               }
            } else {
               this->a_i_v(L_var1);
            }
         }
         return;
      }
      case 2:
      {
         if ((this->a_Vector->size() != 0)) {
            (L_var1 = this->d__i());
            int32_t L_var13 = this->e__i();
            if ((this->b_i == (-1))) {
               (L_var3 = (-1));
               for (int32_t L_var22 = jwrap32(jwint(this->a_Vector->size()) - jwint(1)); (L_var22 >= 0); (L_var22--)) {
                  {
                     f* L_var26 = jcast<f*>(this->a_Vector->elementAt(L_var22));
                     int32_t L_var7{};
                     if (([&]() { auto __l377 = ((L_var7 = ([&]() { auto __l375 = this->a_i_i(L_var22); auto __r376 = L_var26->b__i(); return jwrap32(jwint(__l375) + jwint(__r376)); }()))); auto __r378 = jwrap32(jwint(this->c_i) + jwint(L_var13)); return (__l377 < __r378); }())) {
                        break;
                     }
                     if ((L_var26->a__z() && ([&]() { auto __l381 = L_var7; auto __r382 = ([&]() { auto __l379 = jwrap32(jwint(this->c_i) + jwint(L_var13)); auto __r380 = this->c_i_i(14); return jwrap32(jwint(__l379) + jwint(__r380)); }()); return (__l381 <= __r382); }()))) {
                        (L_var3 = L_var22);
                     }
                  }
               }
            } else {
               int32_t L_var4 = this->b_i;
               h* L_var16 = this;
               int32_t L_var5 = jwrap32(jwint(L_var4) + jwint(1));
               int32_t L_var10000{};
               while (true) {
                  {
                     if (([&]() { auto __l383 = L_var5; auto __r384 = L_var16->a_Vector->size(); return (__l383 >= __r384); }())) {
                        (L_var10000 = (-1));
                        break;
                     }
                     if ((jcast<f*>(L_var16->a_Vector->elementAt(L_var5)))->a__z()) {
                        (L_var10000 = L_var5);
                        break;
                     }
                     (L_var5++);
                  }
               }
               (L_var3 = L_var10000);
               if (((L_var10000 != (-1)) && ([&]() { auto __l387 = this->a_i_i(L_var3); auto __r388 = ([&]() { auto __l385 = jwrap32(jwint(this->c_i) + jwint(L_var13)); auto __r386 = this->c_i_i(14); return jwrap32(jwint(__l385) + jwint(__r386)); }()); return (__l387 > __r388); }()))) {
                  (L_var3 = (-1));
               }
            }
            if ((L_var3 == (-1))) {
               if (((this->c_i_i(5) == 128) && (this->c_i >= jwrap32(jwint(L_var1) - jwint(L_var13))))) {
                  h* L_var18 = this;
                  (this->c_i = 0);
                  int32_t L_var23 = 0;
                  while (true) {
                     {
                        if (([&]() { auto __l389 = L_var23; auto __r390 = jwrap32(jwint(L_var18->a_Vector->size()) - jwint(1)); return (__l389 >= __r390); }())) {
                           return;
                        }
                        f* L_var27 = jcast<f*>(L_var18->a_Vector->elementAt(L_var23));
                        if ((!L_var18->a_i_z(L_var23))) {
                           L_var18->a_i_v((-1));
                           break;
                        }
                        if (L_var27->a__z()) {
                           L_var18->a_i_v(L_var23);
                           break;
                        }
                        (L_var23++);
                     }
                  }
               } else {
                  ([&]() -> decltype(auto) { auto& __a393 = this->c_i; auto __v394 = ([&]() { auto __l391 = this->c_i; auto __r392 = this->c_i_i(14); return jwrap32(jwint(__l391) + jwint(__r392)); }()); return (__a393 = __v394); }());
                  if ((L_var1 <= L_var13)) {
                     (this->c_i = 0);
                  } else {
                     if ((this->c_i > jwrap32(jwint(L_var1) - jwint(L_var13)))) {
                        (this->c_i = jwrap32(jwint(L_var1) - jwint(L_var13)));
                     }
                  }
                  if (((this->b_i != (-1)) && (!this->a_i_z(this->b_i)))) {
                     this->a_i_v((-1));
                     return;
                  }
               }
            } else {
               this->a_i_v(L_var3);
            }
         }
         return;
      }
      case 5:
      {
         (L_var3 = ((int32_t)(((int8_t)(1)))));
         break;
      }
      case 6:
      case 24:
      {
         (L_var3 = ((int32_t)(((int8_t)(2)))));
         break;
      }
      case 7:
      {
         (L_var3 = ((int32_t)(((int8_t)(0)))));
         break;
      }
      default:
      {
         return;
      }
      }
   }
   if ((((this->c_Ai[L_var3] & 65536)) != 0)) {
      int32_t L_var8{};
      if ((((L_var8 = ((int32_t)(((int16_t)(this->c_Ai[L_var3])))))) == (-2))) {
         if ((L_var2 != nullptr)) {
            (o::__ci(),o::a_m)->d_i_v(L_var2->a_i);
            return;
         }
      } else {
         (o::__ci(),o::a_m)->d_i_v(L_var8);
      }
   }
}
void h::c__v() {
   if ((this->a_b != nullptr)) {
      int32_t L_var1 = ((this->d_i != (-1)) ? (o::__ci(), o::a_ii_i(this->d_i, 0)) : 0);
      int32_t L_var2 = ([&]() { auto __l395 = this->c__i(); auto __r396 = (jshl(int32_t(this->c_i_i(8)),1)); return jwrap32(jwint(__l395) - jwint(__r396)); }());
      if ((this->c_i_i(1) != 8)) {
         (L_var1 = jwrap32(jwint(L_var2) - jwint(L_var1)));
      } else {
         (L_var1 = L_var2);
      }
      if ((L_var1 < this->a_b->b_i)) {
         if ((this->e_i >= 3000)) {
            if ((this->g_i > 0)) {
               (this->f_i = jdiv(int32_t(jwrap32(jwint((jwrap32(jwint(this->e_i) - jwint(3000)))) * jwint(20))),int32_t(1000)));
               if ((this->f_i > jwrap32(jwint(this->a_b->b_i) - jwint(L_var1)))) {
                  (this->f_i = jwrap32(jwint(this->a_b->b_i) - jwint(L_var1)));
                  (this->e_i = 0);
                  (this->g_i = (-1));
               }
            } else {
               (this->f_i = jwrap32(jwint(jwrap32(jwint(this->a_b->b_i) - jwint(L_var1))) - jwint(jdiv(int32_t(jwrap32(jwint((jwrap32(jwint(this->e_i) - jwint(3000)))) * jwint(20))),int32_t(1000)))));
               if ((this->f_i <= 0)) {
                  (this->f_i = 0);
                  (this->e_i = 0);
                  (this->g_i = 1);
               }
            }
         }
         (this->e_i = jwrap32(jwint(this->e_i) + jwint((o::__ci(),o::a_i))));
      }
   }
}
void h::d__v() {
   JGraphics L_var1 = (o::__ci(), o::a__Graphics());
   int32_t L_var2 = this->b_i_i(2);
   int32_t L_var3 = ((this->c_i_i(4) == 64) ? ([&]() { auto __l399 = (jshr(int32_t(([&]() { auto __l397 = (o::__ci(),o::b_i); auto __r398 = this->c__i(); return jwrap32(jwint(__l397) - jwint(__r398)); }())),1)); auto __r400 = ((((o::__ci(), o::b__i()) == 3) ? (o::__ci(), o::d__i()) : 0)); return jwrap32(jwint(__l399) + jwint(__r400)); }()) : ([&]() { auto __l401 = this->c_i_i(9); auto __r402 = ((((o::__ci(), o::b__i()) == 3) ? (o::__ci(), o::d__i()) : 0)); return jwrap32(jwint(__l401) + jwint(__r402)); }()));
   int32_t L_var4 = ((this->c_i_i(4) == 64) ? jshr(int32_t(([&]() { auto __l405 = ([&]() { auto __l403 = (o::__ci(),o::c_i); auto __r404 = (((o::__ci(), o::b__z()) ? (o::__ci(), o::c__i()) : 0)); return jwrap32(jwint(__l403) - jwint(__r404)); }()); auto __r406 = this->b_i_i(1); return jwrap32(jwint(__l405) - jwint(__r406)); }())),1) : ([&]() { auto __l407 = this->c_i_i(10); auto __r408 = ((((o::__ci(), o::b__i()) == 1) ? (o::__ci(), o::c__i()) : 0)); return jwrap32(jwint(__l407) + jwint(__r408)); }()));
   int32_t L_var5 = this->c__i();
   int32_t L_var6 = this->b_i_i(1);
   if ((m::__ci(), m::a_hiiiii_z(this, 1, L_var3, L_var4, L_var5, L_var6))) {
      L_var1->setColor(this->c_i_i(22));
      L_var1->fillRect(L_var3, L_var4, L_var5, L_var6);
      L_var1->setColor(this->c_i_i(23));
      L_var1->drawRect(L_var3, L_var4, jwrap32(jwint(L_var5) - jwint(1)), jwrap32(jwint(L_var6) - jwint(1)));
   }
   if ((L_var2 > 0)) {
      L_var1->setClip(L_var3, L_var4, L_var5, L_var2);
      if ((m::__ci(), m::a_hiiiii_z(this, 2, L_var3, L_var4, L_var5, L_var2))) {
         L_var1->setColor(this->c_i_i(20));
         L_var1->fillRect(L_var3, L_var4, L_var5, L_var2);
      }
      L_var1->setClip(L_var3, L_var4, L_var5, L_var2);
      if ((m::__ci(), m::a_hiiiii_z(this, 3, L_var3, L_var4, L_var5, L_var2))) {
         L_var1->setClip(L_var3, L_var4, L_var5, L_var2);
         int32_t L_var7 = this->c_i_i(8);
         int32_t L_var8 = ((this->d_i != (-1)) ? (o::__ci(), o::a_ii_i(this->d_i, 0)) : 0);
         int32_t L_var9 = ((this->a_b != nullptr) ? this->a_b->b_i : 0);
         int32_t L_var10 = jwrap32(jwint(L_var5) - jwint((jshl(int32_t(L_var7),1))));
         int32_t L_var11{};
         if ((this->c_i_i(1) != 8)) {
            (L_var11 = jwrap32(jwint(L_var10) - jwint(L_var8)));
         } else {
            (L_var11 = L_var10);
         }
         if ((this->d_i != (-1))) {
            int32_t L_var12 = L_var7;
            {
               switch (this->c_i_i(1)) {
               case 4:
               {
                  (L_var12 = jwrap32(jwint(L_var7) + jwint((jwrap32(jwint(L_var10) - jwint(L_var8))))));
                  break;
               }
               case 8:
               {
                  (L_var12 = jwrap32(jwint(L_var7) + jwint((jshr(int32_t(jwrap32(jwint(L_var10) - jwint(L_var8))),1)))));
               }
               }
            }
            ([&]() -> decltype(auto) { auto __p411 = jwrap32(jwint(L_var3) + jwint(L_var12)); auto __p412 = ([&]() { auto __l409 = L_var4; auto __r410 = this->c_i_i(6); return jwrap32(jwint(__l409) + jwint(__r410)); }()); auto __p413 = this->d_i; auto __p414 = 20; return (o::__ci(), o::a_iiii_v(__p411, __p412, __p413, __p414)); }());
         }
         if ((this->a_b != nullptr)) {
            int32_t L_var38 = L_var7;
            {
               switch (this->c_i_i(1)) {
               case 0:
               {
                  (L_var38 = jwrap32(jwint(L_var7) + jwint(L_var8)));
                  break;
               }
               case 4:
               {
                  (L_var38 = ([&]() { auto __l415 = L_var7; auto __r416 = jmath_max<int32_t>(jwrap32(jwint(L_var11) - jwint(L_var9)), 0); return jwrap32(jwint(__l415) + jwint(__r416)); }()));
                  break;
               }
               case 8:
               {
                  (L_var38 = ([&]() { auto __l417 = L_var7; auto __r418 = (jshr(int32_t(jmath_max<int32_t>(jwrap32(jwint(L_var10) - jwint(L_var9)), 0)),1)); return jwrap32(jwint(__l417) + jwint(__r418)); }()));
               }
               }
            }
            int32_t L_var13 = 0;
            if ((L_var5 < (o::__ci(),o::b_i))) {
               (L_var13 = jshr(int32_t(([&]() { auto __l419 = jwrap32(jwint((o::__ci(),o::b_i)) - jwint(L_var5)); auto __r420 = (((o::__ci(), o::a__z()) ? (o::__ci(), o::d__i()) : 0)); return jwrap32(jwint(__l419) - jwint(__r420)); }())),1));
            }
            L_var1->setClip(jwrap32(jwint(jwrap32(jwint(L_var38) - jwint(1))) + jwint(L_var13)), jwrap32(jwint(L_var4) - jwint(1)), jwrap32(jwint(L_var11) + jwint(2)), jwrap32(jwint(L_var2) + jwint(2)));
            ([&]() -> decltype(auto) { auto __p423 = jwrap32(jwint(jwrap32(jwint(L_var3) + jwint(L_var38))) - jwint(this->f_i)); auto __p424 = ([&]() { auto __l421 = L_var4; auto __r422 = this->c_i_i(6); return jwrap32(jwint(__l421) + jwint(__r422)); }()); auto __p425 = this->c_i_i(24); auto __p426 = this->c_i_i(25); return this->a_b->a_iiii_v(__p423, __p424, __p425, __p426); }());
         }
      }
   }
   if ((this->c_i_i(2) == 16)) {
      int32_t L_var30 = (o::__ci(), o::c__i());
      int32_t L_var32 = (o::__ci(), o::d__i());
      L_var1->setClip(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
      L_var1->setColor(this->c_i_i(21));
      {
         switch ((o::__ci(), o::b__i())) {
         case 1:
         {
            L_var1->fillRect(0, 0, (o::__ci(),o::b_i), L_var30);
            break;
         }
         case 2:
         {
            L_var1->fillRect(0, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(L_var30)), (o::__ci(),o::b_i), L_var30);
            break;
         }
         case 3:
         {
            L_var1->fillRect(0, 0, L_var32, (o::__ci(),o::c_i));
            break;
         }
         case 4:
         {
            L_var1->fillRect(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(L_var32)), 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
         }
         }
      }
   }
   L_var1->setClip(L_var3, jwrap32(jwint(L_var4) + jwint(L_var2)), L_var5, jwrap32(jwint(L_var6) - jwint(L_var2)));
   (m::__ci(), m::a_hiiiii_z(this, 4, L_var3, jwrap32(jwint(L_var4) + jwint(L_var2)), L_var5, jwrap32(jwint(L_var6) - jwint(L_var2))));
   int32_t L_var31 = ([&]() { auto __l427 = L_var3; auto __r428 = this->c_i_i(15); return jwrap32(jwint(__l427) + jwint(__r428)); }());
   int32_t L_var33 = ([&]() { auto __l429 = jwrap32(jwint(L_var4) + jwint(L_var2)); auto __r430 = this->c_i_i(17); return jwrap32(jwint(__l429) + jwint(__r430)); }());
   int32_t L_var34 = this->b__i();
   int32_t L_var35 = this->e__i();
   int32_t L_var36 = this->d__i();
   int32_t L_var39 = this->b_i_i(5);
   L_var1->setClip(L_var31, L_var33, L_var34, L_var39);
   (m::__ci(), m::a_hiiiii_z(this, 5, L_var31, L_var33, L_var34, L_var39));
   L_var1->setClip(L_var31, L_var33, L_var34, L_var39);
   if ((this->c_i > 0)) {
      ([&]() -> decltype(auto) { auto __p431 = L_var31; auto __p432 = L_var33; auto __p433 = L_var34; auto __p434 = this->b_i_i(6); return L_var1->setClip(__p431, __p432, __p433, __p434); }());
      if (([&]() -> decltype(auto) { auto __p435 = this; auto __p436 = 6; auto __p437 = L_var31; auto __p438 = L_var33; auto __p439 = L_var34; auto __p440 = this->b_i_i(6); return (m::__ci(), m::a_hiiiii_z(__p435, __p436, __p437, __p438, __p439, __p440)); }())) {
         ([&]() -> decltype(auto) { auto __p449 = ([&]() { auto __l445 = ([&]() { auto __l441 = L_var31; auto __r442 = (o::__ci(), o::a_ii_i(151, 2)); return jwrap32(jwint(__l441) + jwint(__r442)); }()); auto __r446 = (jshr(int32_t(([&]() { auto __l443 = L_var34; auto __r444 = (o::__ci(), o::a_ii_i(151, 0)); return jwrap32(jwint(__l443) - jwint(__r444)); }())),1)); return jwrap32(jwint(__l445) + jwint(__r446)); }()); auto __p450 = ([&]() { auto __l447 = L_var33; auto __r448 = (o::__ci(), o::a_ii_i(151, 3)); return jwrap32(jwint(__l447) + jwint(__r448)); }()); auto __p451 = 151; return (o::__ci(), o::a_iii_v(__p449, __p450, __p451)); }());
      }
   }
   if ((L_var35 < L_var36)) {
      (L_var33 += this->b_i_i(6));
   }
   if ((this->c_i < jwrap32(jwint(L_var36) - jwint(L_var35)))) {
      ([&]() -> decltype(auto) { auto __p452 = L_var31; auto __p453 = jwrap32(jwint(L_var33) + jwint(L_var35)); auto __p454 = L_var34; auto __p455 = this->b_i_i(7); return L_var1->setClip(__p452, __p453, __p454, __p455); }());
      if (([&]() -> decltype(auto) { auto __p456 = this; auto __p457 = 7; auto __p458 = L_var31; auto __p459 = jwrap32(jwint(L_var33) + jwint(L_var35)); auto __p460 = L_var34; auto __p461 = this->b_i_i(7); return (m::__ci(), m::a_hiiiii_z(__p456, __p457, __p458, __p459, __p460, __p461)); }())) {
         ([&]() -> decltype(auto) { auto __p470 = ([&]() { auto __l466 = ([&]() { auto __l462 = L_var31; auto __r463 = (o::__ci(), o::a_ii_i(150, 2)); return jwrap32(jwint(__l462) + jwint(__r463)); }()); auto __r467 = (jshr(int32_t(([&]() { auto __l464 = L_var34; auto __r465 = (o::__ci(), o::a_ii_i(150, 0)); return jwrap32(jwint(__l464) - jwint(__r465)); }())),1)); return jwrap32(jwint(__l466) + jwint(__r467)); }()); auto __p471 = ([&]() { auto __l468 = jwrap32(jwint(jwrap32(jwint(L_var33) + jwint(L_var35))) + jwint(1)); auto __r469 = (o::__ci(), o::a_ii_i(150, 3)); return jwrap32(jwint(__l468) + jwint(__r469)); }()); auto __p472 = 150; return (o::__ci(), o::a_iii_v(__p470, __p471, __p472)); }());
      }
   }
   (L_var6 = this->b_i);
   if (((this->b_i != (-1)) && ((jcast<f*>(this->a_Vector->elementAt(L_var6)))->a_i_i(7) == 2048))) {
      f* L_var25 = jcast<f*>(this->a_Vector->elementAt(L_var6));
      int32_t L_var41 = ([&]() { auto __l473 = L_var31; auto __r474 = h::a_fi_i(L_var25, L_var34); return jwrap32(jwint(__l473) + jwint(__r474)); }());
      (L_var2 = ([&]() { auto __l477 = ([&]() { auto __l475 = L_var33; auto __r476 = this->a_i_i(L_var6); return jwrap32(jwint(__l475) + jwint(__r476)); }()); auto __r478 = this->c_i; return jwrap32(jwint(__l477) - jwint(__r478)); }()));
      (L_var3 = L_var25->a__i());
      (L_var4 = L_var25->b__i());
      L_var1->setClip(L_var41, L_var2, L_var3, L_var4);
      if ((m::__ci(), m::a_hiiiii_z(this, 9, L_var41, L_var2, L_var3, L_var4))) {
         L_var1->setColor(L_var25->a_i_i(21));
         L_var1->fillRect(L_var41, L_var2, L_var3, L_var4);
         L_var1->setColor(L_var25->a_i_i(22));
         L_var1->drawRect(L_var41, L_var2, jwrap32(jwint(L_var3) - jwint(1)), jwrap32(jwint(L_var4) - jwint(1)));
      }
   }
   for (int32_t L_var37 = 0; ([&]() { auto __l479 = L_var37; auto __r480 = this->a_Vector->size(); return (__l479 < __r480); }()); (L_var37++)) {
      {
         f* L_var26 = jcast<f*>(this->a_Vector->elementAt(L_var37));
         if (([&]() { auto __l481 = ((L_var2 = this->a_i_i(L_var37))); auto __r482 = jwrap32(jwint(this->c_i) + jwint(L_var35)); return (__l481 > __r482); }())) {
            break;
         }
         (L_var4 = L_var26->b__i());
         if ((jwrap32(jwint(L_var2) + jwint(L_var4)) >= this->c_i)) {
            int32_t L_var42 = ([&]() { auto __l483 = L_var31; auto __r484 = h::a_fi_i(L_var26, L_var34); return jwrap32(jwint(__l483) + jwint(__r484)); }());
            (L_var2 = jwrap32(jwint(jwrap32(jwint(L_var33) + jwint(L_var2))) - jwint(this->c_i)));
            (L_var3 = L_var26->a__i());
            L_var1->setClip(L_var31, L_var33, L_var34, L_var35);
            (o::__ci(), o::a_iiiiAi_z(L_var42, L_var2, L_var3, L_var4, h::e_Ai));
            if ((m::__ci(), m::a_hiiiii_z(this, 8, L_var42, L_var2, L_var3, L_var4))) {
               bool L_var27 = (L_var37 == this->b_i);
               b* L_var40{};
               if ((((L_var40 = L_var26->a_b)) != nullptr)) {
                  ([&]() -> decltype(auto) { auto __p489 = ([&]() { auto __l485 = L_var42; auto __r486 = L_var26->a_i_i(13); return jwrap32(jwint(__l485) + jwint(__r486)); }()); auto __p490 = ([&]() { auto __l487 = L_var2; auto __r488 = L_var26->a_i_i(11); return jwrap32(jwint(__l487) + jwint(__r488)); }()); auto __p491 = L_var26->a_i_i((L_var26->a_z ? ((L_var27 ? 18 : 15)) : ((L_var27 ? 20 : 19)))); auto __p492 = L_var26->a_i_i(16); return L_var40->a_iiii_v(__p489, __p490, __p491, __p492); }());
               }
            }
         }
      }
   }
   if (((L_var6 != (-1)) && ((jcast<f*>(this->a_Vector->elementAt(L_var6)))->a_i_i(7) == 2048))) {
      f* L_var28 = jcast<f*>(this->a_Vector->elementAt(L_var6));
      int32_t L_var43 = ([&]() { auto __l493 = L_var31; auto __r494 = h::a_fi_i(L_var28, L_var34); return jwrap32(jwint(__l493) + jwint(__r494)); }());
      (L_var2 = ([&]() { auto __l497 = ([&]() { auto __l495 = L_var33; auto __r496 = this->a_i_i(L_var6); return jwrap32(jwint(__l495) + jwint(__r496)); }()); auto __r498 = this->c_i; return jwrap32(jwint(__l497) - jwint(__r498)); }()));
      (L_var3 = L_var28->a__i());
      (L_var4 = L_var28->b__i());
      L_var1->setClip(L_var43, L_var2, L_var3, L_var4);
      (m::__ci(), m::a_hiiiii_z(this, 10, L_var43, L_var2, L_var3, L_var4));
   }
}
void h::d_i_v(int32_t L_var1) {
   Arr<int8_t> L_var3{};
   if ((((L_var3 = jcast<Arr<int8_t>>((o::__ci(), o::a_i_Object(L_var1))))) != nullptr)) {
      try {
         JDataInputStream L_var4 = JDataInputStream::make(JByteArrayInputStream::make(L_var3));
         ([&]() -> decltype(auto) { auto& __a499 = this->a_Ai; auto __v500 = h::a_DataInputStreamAiii_Ai(L_var4, h::f_Ai, 15, 22); return (__a499 = __v500); }());
         ([&]() -> decltype(auto) { auto& __a501 = this->b_Ai; auto __v502 = h::a_DataInputStreamAiii_Ai(L_var4, h::h_Ai, 20, 26); return (__a501 = __v502); }());
      }
      catch (JException& L_var2) {
      }
   }
}
int32_t h::c_i_i(int32_t L_var1) {
   return h::a_iAii_i(L_var1, this->b_Ai, 2);
}
void h::a_ii_v(int32_t L_var1, int32_t L_var2) {
   ([&]() -> decltype(auto) { auto& __a503 = this->a_Ai; auto __v504 = h::a_iiAii_Ai(L_var1, L_var2, this->a_Ai, 1); return (__a503 = __v504); }());
}
void h::b_ii_v(int32_t L_var1, int32_t L_var2) {
   ([&]() -> decltype(auto) { auto& __a505 = this->b_Ai; auto __v506 = h::a_iiAii_Ai(L_var1, L_var2, this->b_Ai, 2); return (__a505 = __v506); }());
}
Arr<int32_t> h::a_DataInputStreamAiii_Ai(JDataInputStream L_var0, Arr<int32_t> L_var1, int32_t L_var2, int32_t L_var3) {
   int32_t L_var4 = L_var0->readInt();
   int32_t L_var10 = L_var1.length();
   if ((L_var4 == 0)) {
      return static_cast<Arr<int32_t>>(nullptr);
   } else {
      int32_t L_var5 = 0;
      for (int32_t L_var6 = L_var10; (jushr(int32_t(L_var4),jwrap32(jwint(L_var6) - jwint(1))) != 0); (L_var6++)) {
         {
            (L_var5 = jwrap32(jwint(L_var6) - jwint(L_var10)));
         }
      }
      Arr<int32_t> L_var13{};
      ([&]() -> decltype(auto) { auto& __a507 = ((L_var13 = newArr<int32_t>(jwrap32(jwint(L_var5) + jwint(2)))))[0]; auto __v508 = L_var4; return (__a507 = __v508); }());
      (L_var13[1] = 0);
      if ((((L_var4 & jushr(int32_t((-1)),jwrap32(jwint(32) - jwint(L_var10))))) != 0)) {
         ([&]() -> decltype(auto) { auto& __a509 = L_var13[1]; auto __v510 = L_var0->readInt(); return (__a509 = __v510); }());
      }
      for (int32_t L_var11 = 0; (L_var11 < L_var5); (L_var11++)) {
         {
            if ((((L_var13[0] & jshl(int32_t(1),jwrap32(jwint(L_var11) + jwint(L_var10))))) != 0)) {
               ([&]() -> decltype(auto) { auto& __a511 = L_var13[jwrap32(jwint(L_var11) + jwint(2))]; auto __v512 = L_var0->readShort(); return (__a511 = ((int32_t)(__v512))); }());
            }
         }
      }
      for (int32_t L_var12 = jwrap32(jwint(jwrap32(jwint(L_var2) + jwint(2))) - jwint(L_var10)); ((L_var12 <= jwrap32(jwint(jwrap32(jwint(L_var3) + jwint(2))) - jwint(L_var10))) && (L_var12 < L_var13.length())); (L_var12++)) {
         {
            bool L_var7 = false;
            int32_t L_var8{};
            int32_t L_var9 = ([&]() { auto __l515 = ([&]() { auto __l513 = ((L_var8 = (0 | jshl(int32_t(((L_var13[L_var12] & 31744))),9)))); auto __r514 = jshl(int32_t(((L_var13[L_var12] & 992))),6); return (__l513 | __r514); }()); auto __r516 = jshl(int32_t(((L_var13[L_var12] & 31))),3); return (__l515 | __r516); }());
            (L_var13[L_var12] = L_var9);
         }
      }
      return L_var13;
   }
}
int32_t h::a_iAii_i(int32_t L_var0, Arr<int32_t> L_var1, int32_t L_var2) {
   Arr<int32_t> L_var3{};
   Arr<int32_t> L_var5{};
   if ((L_var2 == 1)) {
      (L_var5 = h::g_Ai);
      (L_var3 = h::f_Ai);
   } else {
      (L_var5 = h::i_Ai);
      (L_var3 = h::h_Ai);
   }
   int32_t L_var4 = L_var3.length();
   if ((!h::a_iAi_z(L_var0, L_var1))) {
      (L_var1 = L_var5);
   }
   return ((L_var0 < L_var4) ? (L_var1[1] & L_var3[L_var0]) : L_var1[jwrap32(jwint(jwrap32(jwint(L_var0) + jwint(2))) - jwint(L_var4))]);
}
bool h::a_iAi_z(int32_t L_var0, Arr<int32_t> L_var1) {
   return ((L_var1 != nullptr) && (((L_var1[0] & jshl(int32_t(1),L_var0))) != 0));
}
Arr<int32_t> h::a_iiAii_Ai(int32_t L_var0, int32_t L_var1, Arr<int32_t> L_var2, int32_t L_var3) {
   Arr<int32_t> L_var4{};
   int32_t L_var5{};
   if ((L_var3 == 1)) {
      (L_var5 = 16);
      (L_var4 = h::f_Ai);
   } else {
      (L_var5 = 23);
      (L_var4 = h::h_Ai);
   }
   if ((L_var2 == nullptr)) {
      (L_var2 = newArr<int32_t>(L_var5));
   } else {
      if ((L_var2.length() < L_var5)) {
         Arr<int32_t> L_var6 = newArr<int32_t>(L_var5);
         JSystem::arraycopy(L_var2, 0, L_var6, 0, L_var2.length());
         (L_var2 = L_var6);
      }
   }
   (L_var2[0] |= jshl(int32_t(1),L_var0));
   if ((L_var0 < L_var4.length())) {
      (L_var2[1] &= (~L_var4[L_var0]));
      (L_var2[1] |= (L_var1 & L_var4[L_var0]));
   } else {
      (L_var2[jwrap32(jwint(jwrap32(jwint(L_var0) + jwint(2))) - jwint(L_var4.length()))] = L_var1);
   }
   return L_var2;
}
void i::__clinit() {
   __inited = true;
   j::__ci();
}
i::i() {
   this->a_i = 0;
   this->s_i = 0;
   (this->c_b = ((int8_t)(6)));
}
int32_t i::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   (L_var2 = j::a_Abi_i(L_var1, L_var2));
   ([&]() -> decltype(auto) { auto& __a519 = this->a_s; auto __v520 = ((int16_t)((([&]() { auto __l517 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r518 = (L_var1[(L_var2++)] & 255); return (__l517 | __r518); }())))); return (__a519 = __v520); }());
   ([&]() -> decltype(auto) { auto& __a523 = this->d_s; auto __v524 = ((int16_t)((([&]() { auto __l521 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r522 = (L_var1[(L_var2++)] & 255); return (__l521 | __r522); }())))); return (__a523 = __v524); }());
   ([&]() -> decltype(auto) { auto& __a527 = this->b_s; auto __v528 = ((int16_t)((([&]() { auto __l525 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r526 = (L_var1[(L_var2++)] & 255); return (__l525 | __r526); }())))); return (__a527 = __v528); }());
   ([&]() -> decltype(auto) { auto& __a531 = this->c_s; auto __v532 = ((int16_t)((([&]() { auto __l529 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r530 = (L_var1[(L_var2++)] & 255); return (__l529 | __r530); }())))); return (__a531 = __v532); }());
   ([&]() -> decltype(auto) { auto& __a533 = this->a_b; auto __v534 = L_var1[(L_var2++)]; return (__a533 = __v534); }());
   ([&]() -> decltype(auto) { auto& __a535 = this->d_b; auto __v536 = L_var1[(L_var2++)]; return (__a535 = __v536); }());
   ([&]() -> decltype(auto) { auto& __a537 = this->e_b; auto __v538 = L_var1[(L_var2++)]; return (__a537 = __v538); }());
   ([&]() -> decltype(auto) { auto& __a539 = this->f_b; auto __v540 = L_var1[(L_var2++)]; return (__a539 = __v540); }());
   int32_t L_var48 = (++L_var2);
   (L_var2++);
   int32_t L_var8{};
   ([&]() -> decltype(auto) { auto& __a545 = this->d_i; auto __v546 = ([&]() { auto __l543 = ([&]() { auto __l541 = (1140850688 | jshl(int32_t(((L_var1[L_var48] & 255))),16)); auto __r542 = jshl(int32_t(((L_var1[(L_var2++)] & 255))),8); return (__l541 | __r542); }()); auto __r544 = ((L_var8 = (L_var1[(L_var2++)] & 255))); return (__l543 | __r544); }()); return (__a545 = __v546); }());
   if ((L_var8 == 16)) {
      (this->g_b = ((int8_t)(1)));
   } else {
      (this->g_b = ((int8_t)(0)));
   }
   if ((this->d_i != 1140850688)) {
      (this->d_i = 1141969390);
   }
   (this->e_s = ((int16_t)((jwrap32(jwint(this->b_s) - jwint(this->a_s))))));
   if (((this->d_i != 1140850688) && (this->g_b == 0))) {
      int32_t L_var9 = jdiv(int32_t(jwrap32(jwint(this->e_s) * jwint(50))),int32_t(100));
      (this->a_Ab = newArr<int8_t>(L_var9));
      (this->r_i = jshl(int32_t(L_var9),12));
      (this->u_i = 0);
      (this->a_i = jwrap32(jwint(L_var9) + jwint(2)));
      for (int32_t L_var3 = 0; (L_var3 < L_var9); (L_var3++)) {
         {
            (this->a_Ab[L_var3] = ((int8_t)(0)));
         }
      }
      for (int32_t L_var28 = 0; (L_var28 < this->c_i); (L_var28++)) {
         {
            (this->a_Ai[L_var28] = 0);
         }
      }
      int32_t L_var10 = jdiv(int32_t(L_var9),int32_t(20));
      (this->c_i = jwrap32(jwint((jshl(int32_t(L_var10),1))) + jwint(2)));
      (this->a_Ai = newArr<int32_t>(this->c_i));
      (this->b_Ai = newArr<int32_t>(this->c_i));
      (this->b_Ab = newArr<int8_t>(this->c_i));
      (this->c_Ab = newArr<int8_t>(this->c_i));
      (this->c_Ai = newArr<int32_t>(this->c_i));
      (this->d_Ai = newArr<int32_t>(this->c_i));
      for (int32_t L_var29 = 2; (L_var29 <= jwrap32(jwint(L_var10) - jwint(2))); (L_var29++)) {
         {
            int32_t L_var4 = jdiv(int32_t(jwrap32(jwint((jshl(int32_t(jwrap32(jwint(this->a_Ab.length()) - jwint(1))),12))) * jwint(L_var29))),int32_t(L_var10));
            int32_t L_var5 = jdiv(int32_t((jshl(int32_t(jshl(int32_t(jwrap32(jwint(jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(2)))) + jwint(24))),12)),1))),int32_t(9));
            int32_t L_var6 = jdiv(int32_t((jshl(int32_t(jwrap32(jwint(jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(2)))) + jwint(10))),12))),int32_t(3));
            int32_t L_var7 = jwrap32(jwint(L_var5) * jwint(3));
            this->a_iiiiii_v(L_var5, L_var7, (-1), L_var6, L_var4, 1);
            (L_var5 = jdiv(int32_t((jshl(int32_t(jshl(int32_t(jwrap32(jwint(jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(2)))) + jwint(24))),12)),1))),int32_t(9)));
            (L_var6 = jdiv(int32_t((jshl(int32_t(jwrap32(jwint(jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(2)))) + jwint(10))),12))),int32_t(3)));
            (L_var7 = jwrap32(jwint(L_var5) * jwint(3)));
            this->a_iiiiii_v(L_var5, L_var7, 1, L_var6, L_var4, 1);
         }
      }
   }
   return L_var2;
}
void i::a__v() {
   (this->e_i = jshl(int32_t(this->a_s),16));
   (this->g_i = jshl(int32_t(this->b_s),16));
   (this->f_i = jwrap32(jwint((jshl(int32_t(this->d_s),16))) - jwint(1966080)));
   (this->h_i = jwrap32(jwint((jshl(int32_t(this->c_s),16))) + jwint(1966080)));
   (this->b_i = jshl(int32_t(this->c_s),16));
}
void i::a_ific_v(int32_t L_var1, float L_var2, int32_t L_var3, c* L_var4) {
   if ((this->d_i != 1140850688)) {
      (this->t_i = 0);
      float L_var5 = 230.0f;
      if ((L_var2 > L_var5)) {
         (L_var2 = L_var5);
      } else {
         if ((L_var2 < (-L_var5))) {
            (L_var2 = (-L_var5));
         }
      }
      int32_t L_var10 = jf2i(jmath_abs<float>(L_var2));
      if ((this->g_b == 0)) {
         (L_var1 = ((int32_t)((jdiv(int64_t(jwrap64(jwlong(((int64_t)((jshl(int32_t(jwrap32(jwint(this->a_Ab.length()) - jwint(1))),12))))) * jwlong(((int64_t)(L_var1))))),int64_t((int64_t)65536LL))))));
         int32_t L_var6{};
         int32_t L_var7 = jshl(int32_t(((L_var6 = jdiv(int32_t((jshl(int32_t(jwrap32(jwint(L_var10) * jwint(100))),12))),int32_t(1500))))),1);
         this->a_iiiiii_v(L_var6, L_var7, (-1), 20480, jwrap32(jwint(L_var1) - jwint((jshl(int32_t(L_var3),2)))), 0);
         this->a_iiiiii_v(L_var6, L_var7, 1, 20480, jwrap32(jwint(L_var1) + jwint((jshl(int32_t(L_var3),2)))), 0);
      }
      (L_var4->j_f /= 3.0f);
      (L_var4->k_f /= 3.0f);
      if ((this->g_b == 0)) {
         this->a_d_v(j::a_d);
         int32_t L_var11 = jwrap32(jwint(j::a_d->f_i) + jwint((jshl(int32_t(this->c_s),16))));
         (L_var1 = jdiv(int32_t(jwrap32(jwint(L_var10) * jwint(500))),int32_t(230)));
         int32_t L_var12 = jdiv(int32_t(jwrap32(jwint(L_var10) * jwint(6))),int32_t(230));
         int32_t L_var13 = jdiv(int32_t(jwrap32(jwint(L_var10) * jwint(800))),int32_t(230));
         (m::__ci(),m::b_n)->a_iiiiiiiii_v(L_var12, (m::__ci(),m::a_c)->c_d->c_i, L_var11, L_var1, jshr(int32_t(L_var1),2), 325, 30, L_var13, jdiv(int32_t(L_var13),int32_t(6)));
         (m::__ci(),m::b_n)->a_iiiiiiiii_v(L_var12, (m::__ci(),m::a_c)->c_d->c_i, L_var11, L_var1, jshr(int32_t(L_var1),2), 35, 30, L_var13, jdiv(int32_t(L_var13),int32_t(6)));
      }
   }
}
void i::a_iic_v(int32_t L_var1, int32_t L_var2, c* L_var3) {
   (this->t_i = jwrap32(jwint(this->t_i) + jwint((o::__ci(),o::a_i))));
   if ((!(m::__ci(),m::a_z))) {
      float L_var5 = (((float)((jwrap32(jwint(L_var1) - jwint(this->e_i))))) / ((float)((jwrap32(jwint(this->g_i) - jwint(this->e_i))))));
      float L_var9 = (((float)((jwrap32(jwint(L_var2) - jwint(this->f_i))))) / ((float)((jwrap32(jwint(this->h_i) - jwint(this->f_i))))));
      if ((this->f_b < this->d_b)) {
         int32_t L_var4 = jwrap32(jwint(this->d_b) - jwint(this->f_b));
         (L_var1 = jwrap32(jwint(this->f_b) + jwint(jf2i(((L_var5 * ((float)(L_var4))))))));
      } else {
         int32_t L_var13 = jwrap32(jwint(this->f_b) - jwint(this->d_b));
         (L_var1 = jwrap32(jwint(this->d_b) + jwint(jf2i(((((1.0f - L_var5)) * ((float)(L_var13))))))));
      }
      if ((this->e_b < this->a_b)) {
         int32_t L_var14 = jwrap32(jwint(this->a_b) - jwint(this->e_b));
         (L_var2 = jwrap32(jwint(this->e_b) + jwint(jf2i(((L_var9 * ((float)(L_var14))))))));
      } else {
         int32_t L_var15 = jwrap32(jwint(this->e_b) - jwint(this->a_b));
         (L_var2 = jwrap32(jwint(this->a_b) + jwint(jf2i(((((1.0f - L_var9)) * ((float)(L_var15))))))));
      }
      (L_var3->d_f += ((float)((jshl(int32_t(L_var1),5)))));
      (L_var3->e_f += ((float)((jshl(int32_t(L_var2),5)))));
      if ((L_var3->j_f > 0.0f)) {
         (L_var3->j_f = (L_var3->j_f - ((((float)((o::__ci(),o::a_i))) * L_var3->j_f) / ((float)(400)))));
         if ((L_var3->j_f < 0.0f)) {
            (L_var3->j_f = 0.0f);
         }
      } else {
         if ((L_var3->j_f < 0.0f)) {
            (L_var3->j_f = (L_var3->j_f - ((((float)((o::__ci(),o::a_i))) * L_var3->j_f) / ((float)(400)))));
            if ((L_var3->j_f > 0.0f)) {
               (L_var3->j_f = 0.0f);
            }
         }
      }
      if ((L_var3->k_f > 0.0f)) {
         (L_var3->k_f = (L_var3->k_f - ((((float)((o::__ci(),o::a_i))) * L_var3->k_f) / ((float)(400)))));
         if ((L_var3->k_f < 0.0f)) {
            (L_var3->k_f = 0.0f);
         }
      } else {
         if ((L_var3->k_f < 0.0f)) {
            (L_var3->k_f = (L_var3->k_f - ((((float)((o::__ci(),o::a_i))) * L_var3->k_f) / ((float)(400)))));
            if ((L_var3->k_f > 0.0f)) {
               (L_var3->k_f = 0.0f);
            }
         }
      }
      if ((this->d_i != 1140850688)) {
         float L_var7 = (1.0f / (c::__ci(),c::a_Af)[(m::__ci(),m::a_c)->d_i]);
         float L_var11 = (((float)((o::__ci(),o::a_i))) * 0.0014f);
         if (((m::__ci(),m::a_c)->a_f > 0.0f)) {
            ((m::__ci(),m::a_c)->a_f = ((m::__ci(),m::a_c)->a_f - (((m::__ci(),m::a_c)->a_f * L_var7) * L_var11)));
            if (((m::__ci(),m::a_c)->a_f < 0.0f)) {
               ((m::__ci(),m::a_c)->a_f = 0.0f);
            }
         } else {
            ((m::__ci(),m::a_c)->a_f = ((m::__ci(),m::a_c)->a_f - (((m::__ci(),m::a_c)->a_f * L_var7) * L_var11)));
            if (((m::__ci(),m::a_c)->a_f > 0.0f)) {
               ((m::__ci(),m::a_c)->a_f = 0.0f);
            }
         }
         if (((m::__ci(),m::a_c)->b_f > 0.0f)) {
            ((m::__ci(),m::a_c)->b_f = ((m::__ci(),m::a_c)->b_f - (((m::__ci(),m::a_c)->b_f * L_var7) * L_var11)));
            if (((m::__ci(),m::a_c)->b_f < 0.0f)) {
               ((m::__ci(),m::a_c)->b_f = 0.0f);
            }
         } else {
            ((m::__ci(),m::a_c)->b_f = ((m::__ci(),m::a_c)->b_f - (((m::__ci(),m::a_c)->b_f * L_var7) * L_var11)));
            if (((m::__ci(),m::a_c)->b_f > 0.0f)) {
               ((m::__ci(),m::a_c)->b_f = 0.0f);
            }
         }
      }
      if (((this->t_i > 150) && (this->d_i != 1140850688))) {
         this->a_d_v(j::a_d);
         (L_var1 = jwrap32(jwint(j::a_d->f_i) + jwint((jshl(int32_t(this->c_s),16)))));
         ((m::__ci(),m::c_n)->b_i = L_var1);
         ((m::__ci(),m::c_n)->c_i = 60000);
         (L_var2 = jdiv(int32_t((g::__ci(),g::a_Ai)[4]),int32_t(60)));
         (m::__ci(),m::c_n)->b_iiiiiiiiii_v(L_var2, (m::__ci(),m::a_c)->c_d->c_i, (m::__ci(),m::a_c)->c_d->f_i, jshl(int32_t((c::__ci(),c::a_Ai)[0]),15), 0, 0, 0, 0, 4000, 666);
         (this->t_i = 0);
      }
      if ((this->d_i != 1140850688)) {
         ((m::__ci(),m::a_c)->b_b = ((int8_t)(8)));
      }
      ((m::__ci(),m::a_z) = true);
   }
}
void i::a_iiiiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6) {
   for (int32_t L_var7 = 0; (L_var7 < this->c_i); (L_var7++)) {
      {
         if ((this->a_Ai[L_var7] == 0)) {
            (this->a_Ai[L_var7] = jdiv(int32_t(jwrap32(jwint(L_var1) * jwint(50))),int32_t(100)));
            (this->b_Ai[L_var7] = jdiv(int32_t(jwrap32(jwint(L_var2) * jwint(50))),int32_t(100)));
            (this->b_Ab[L_var7] = ((int8_t)(L_var3)));
            (this->c_Ab[L_var7] = ((int8_t)(L_var6)));
            (this->c_Ai[L_var7] = jdiv(int32_t(jwrap32(jwint(L_var4) * jwint(50))),int32_t(100)));
            (this->d_Ai[L_var7] = L_var5);
            return;
         }
      }
   }
}
void i::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   int32_t L_var13 = ([&]() { auto __l547 = (o::__ci(),o::a_i); auto __r548 = (o::__ci(), o::a__i()); return jwrap32(jwint(__l547) * jwint(__r548)); }());
   if ((this->d_i != 1140850688)) {
      if ((!(m::__ci(),m::b_z))) {
         (this->u_i += L_var13);
         if ((this->u_i > 150)) {
            this->a_d_v(j::a_d);
            int32_t L_var4 = jwrap32(jwint(j::a_d->c_i) + jwint((jshl(int32_t(this->a_s),16))));
            int32_t L_var5 = jwrap32(jwint(j::a_d->c_i) + jwint((jshl(int32_t(this->b_s),16))));
            int32_t L_var6 = jwrap32(jwint(j::a_d->f_i) + jwint((jshl(int32_t(this->d_s),16))));
            int32_t L_var7 = jwrap32(jwint(j::a_d->f_i) + jwint((jshl(int32_t(this->c_s),16))));
            ((m::__ci(),m::c_n)->b_i = L_var7);
            ((m::__ci(),m::c_n)->c_i = 60000);
            (m::__ci(),m::c_n)->a_iiiiiiiiiii_v(1, L_var4, L_var6, L_var5, L_var6, 0, 0, 0, 0, 4000, 666);
            (this->u_i = 0);
         }
      }
      if (((!(m::__ci(),m::b_z)) && (this->g_b == 0))) {
         (this->s_i += L_var13);
         for (int32_t L_var19 = 0; (L_var19 < this->a_Ab.length()); (L_var19++)) {
            {
               (this->a_Ab[L_var19] = ((int8_t)(0)));
            }
         }
         for (int32_t L_var20 = 0; (L_var20 < this->c_i); (L_var20++)) {
            {
               if ((this->a_Ai[L_var20] != 0)) {
                  if ((this->c_Ab[L_var20] != 1)) {
                     (this->a_Ai[L_var20] = jwrap32(jwint(this->a_Ai[L_var20]) - jwint((jshr(int32_t(jwrap32(jwint(L_var13) * jwint(28))),3)))));
                     (this->b_Ai[L_var20] = jwrap32(jwint(this->b_Ai[L_var20]) - jwint((jshr(int32_t(jwrap32(jwint(L_var13) * jwint(12))),3)))));
                     (this->c_Ai[L_var20] = jwrap32(jwint(this->c_Ai[L_var20]) - jwint((jshr(int32_t(jwrap32(jwint(L_var13) * jwint(4))),3)))));
                  }
                  (this->d_Ai[L_var20] = jwrap32(jwint(this->d_Ai[L_var20]) + jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(this->b_Ab[L_var20]) * jwint(this->c_Ai[L_var20]))) * jwint(L_var13))),6)))));
                  if (((this->b_Ai[L_var20] <= 0) || (this->c_Ai[L_var20] <= 0))) {
                     (this->a_Ai[L_var20] = 0);
                  }
                  if ((this->a_Ai[L_var20] <= 0)) {
                     (this->a_Ai[L_var20] = 0);
                  } else {
                     if (((this->d_Ai[L_var20] < 0) || (jshr(int32_t(this->d_Ai[L_var20]),12) >= jshr(int32_t(this->r_i),12)))) {
                        (this->b_Ab[L_var20] = ((int8_t)(((-this->b_Ab[L_var20])))));
                        if ((this->d_Ai[L_var20] < 0)) {
                           (this->d_Ai[L_var20] = 0);
                        } else {
                           if ((jshr(int32_t(this->d_Ai[L_var20]),12) >= jshr(int32_t(this->r_i),12))) {
                              (this->d_Ai[L_var20] = jshl(int32_t(jwrap32(jwint((jshr(int32_t(this->r_i),12))) - jwint(1))),12));
                           }
                        }
                        if ((this->c_Ab[L_var20] != 1)) {
                           (this->a_Ai[L_var20] = jwrap32(jwint(this->a_Ai[L_var20]) - jwint((jshr(int32_t(jwrap32(jwint(28) * jwint((jshl(int32_t(L_var13),1))))),3)))));
                           (this->b_Ai[L_var20] = jwrap32(jwint(this->b_Ai[L_var20]) - jwint((jshr(int32_t(jwrap32(jwint(12) * jwint((jshl(int32_t(L_var13),1))))),3)))));
                           (this->c_Ai[L_var20] = jwrap32(jwint(this->c_Ai[L_var20]) - jwint((jshr(int32_t(jwrap32(jwint(4) * jwint((jshl(int32_t(L_var13),1))))),3)))));
                        }
                     }
                  }
                  int32_t L_var24{};
                  if ((((this->a_Ai[L_var20] > 0) && (((L_var24 = jshr(int32_t(this->d_Ai[L_var20]),12))) >= 0)) && (L_var24 < this->a_Ab.length()))) {
                     (this->a_Ab[L_var24] = ((int8_t)((jwrap32(jwint(this->a_Ab[L_var24]) + jwint((jshr(int32_t(this->a_Ai[L_var20]),12))))))));
                     bool L_var27 = false;
                     int32_t L_var30{};
                     if ((((L_var30 = jshr(int32_t(this->b_Ai[L_var20]),12))) == 0)) {
                        (L_var30 = 1);
                     }
                     int32_t L_var8 = jdiv(int32_t(180),int32_t(L_var30));
                     for (int32_t L_var9 = 1; (L_var9 < L_var30); (L_var9++)) {
                        {
                           int32_t L_var10 = jshr(int32_t(jdiv(int32_t(jwrap32(jwint(this->a_Ai[L_var20]) * jwint((jshr(int32_t(jwrap32(jwint((m::__ci(),m::b_As)[jwrap32(jwint(90) + jwint(jwrap32(jwint(L_var8) * jwint(L_var9))))]) + jwint(360))),1))))),int32_t(360))),12);
                           if ((jwrap32(jwint(L_var24) - jwint(L_var9)) >= 0)) {
                              (this->a_Ab[jwrap32(jwint(L_var24) - jwint(L_var9))] = ((int8_t)((jwrap32(jwint(this->a_Ab[jwrap32(jwint(L_var24) - jwint(L_var9))]) + jwint(L_var10))))));
                           }
                           if ((jwrap32(jwint(L_var24) + jwint(L_var9)) < this->a_Ab.length())) {
                              (this->a_Ab[jwrap32(jwint(L_var24) + jwint(L_var9))] = ((int8_t)((jwrap32(jwint(this->a_Ab[jwrap32(jwint(L_var24) + jwint(L_var9))]) + jwint(L_var10))))));
                           }
                        }
                     }
                  }
               }
            }
         }
         for (int32_t L_var21 = 0; (L_var21 < this->a_Ab.length()); (L_var21++)) {
            {
               if (((((L_var21 > 0) && (this->a_Ab[jwrap32(jwint(L_var21) - jwint(1))] < this->a_Ab[L_var21])) && (L_var21 < jwrap32(jwint(this->a_Ab.length()) - jwint(1)))) && (this->a_Ab[jwrap32(jwint(L_var21) + jwint(1))] < this->a_Ab[L_var21]))) {
                  (this->a_Ab[L_var21]--);
               }
            }
         }
      }
      this->a_d_v(j::a_d);
      (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
      (d::__ci(),d::a_d)->a_ii_v(jshl(int32_t(this->a_s),16), jshl(int32_t(this->c_s),16));
      int32_t L_var22 = jshr(int32_t((d::__ci(),d::g_i)),16);
      int32_t L_var25 = jshr(int32_t((d::__ci(),d::h_i)),16);
      (d::__ci(),d::a_d)->a_ii_v(jshl(int32_t(this->b_s),16), jshl(int32_t(this->d_s),16));
      int32_t L_var28 = jshr(int32_t((d::__ci(),d::g_i)),16);
      int32_t L_var31 = jshr(int32_t((d::__ci(),d::h_i)),16);
      int32_t L_var34 = jwrap32(jwint(L_var28) - jwint(L_var22));
      if ((this->g_b != 0)) {
         int32_t L_var40 = (m::__ci(), m::c_i_i(this->d_i));
         Arr<int32_t> L_var44 = (p::__ci(),p::a_Ai);
         Arr<int32_t> L_var15 = (p::__ci(),p::b_Ai);
         (L_var44[0] = L_var22);
         (L_var15[0] = L_var25);
         (L_var44[1] = L_var28);
         (L_var15[1] = L_var25);
         (L_var44[2] = L_var28);
         (L_var15[2] = L_var31);
         (L_var44[3] = L_var22);
         (L_var15[3] = L_var31);
         L_var2->fillPolygon(L_var44, 0, L_var15, 0, 4, L_var40);
         return;
      }
      int32_t L_var39 = jshr(int32_t(jdiv(int32_t((jshl(int32_t(jshl(int32_t(L_var34),8)),10))),int32_t(this->a_Ab.length()))),8);
      Arr<int32_t> L_var43 = (p::__ci(),p::a_Ai);
      Arr<int32_t> L_var14 = (p::__ci(),p::b_Ai);
      (L_var43[0] = L_var28);
      (L_var14[0] = L_var31);
      (L_var43[1] = L_var22);
      (L_var14[1] = L_var31);
      int32_t L_var17 = 2;
      for (int32_t L_var11 = 2; (L_var11 < jwrap32(jwint(this->a_Ab.length()) + jwint(2))); (L_var11++)) {
         {
            if ((L_var11 > 2)) {
               int32_t L_var35 = ((int32_t)(this->a_Ab[jwrap32(jwint(L_var11) - jwint(2))]));
               int32_t L_var12 = 0;
               for (int32_t L_var32 = jwrap32(jwint(L_var11) + jwint(1)); ((L_var32 < jwrap32(jwint(this->a_Ab.length()) + jwint(2))) && (this->a_Ab[jwrap32(jwint(L_var32) - jwint(2))] == L_var35)); (L_var32++)) {
                  {
                     (L_var12++);
                  }
               }
               (L_var11 += L_var12);
            }
            if ((L_var11 == jwrap32(jwint(this->a_Ab.length()) + jwint(1)))) {
               (L_var43[L_var17] = L_var28);
               (L_var14[L_var17] = L_var25);
            } else {
               (L_var43[L_var17] = jwrap32(jwint((jshr(int32_t(jwrap32(jwint((jwrap32(jwint(L_var11) - jwint(2)))) * jwint(L_var39))),10))) + jwint(L_var22)));
               (L_var14[L_var17] = jwrap32(jwint((jshr(int32_t(jwrap32(jwint((-this->a_Ab[jwrap32(jwint(L_var11) - jwint(2))])) * jwint(L_var39))),10))) + jwint(L_var25)));
            }
            (L_var17++);
         }
      }
      int32_t L_var46 = (m::__ci(), m::c_i_i(this->d_i));
      L_var2->fillPolygon(L_var43, 0, L_var14, 0, L_var17, L_var46);
   } else {
      if ((!(m::__ci(),m::b_z))) {
         (this->u_i += L_var13);
         if ((this->u_i > 150)) {
            this->a_d_v(j::a_d);
            int32_t L_var23 = jwrap32(jwint(j::a_d->c_i) + jwint((jshl(int32_t(this->a_s),16))));
            int32_t L_var26 = jwrap32(jwint(j::a_d->c_i) + jwint((jshl(int32_t(this->b_s),16))));
            int32_t L_var29 = jwrap32(jwint(j::a_d->f_i) + jwint((jshl(int32_t(this->d_s),16))));
            int32_t L_var33 = jwrap32(jwint(j::a_d->f_i) + jwint((jshl(int32_t(this->c_s),16))));
            int32_t L_var36 = 0;
            int32_t L_var41 = 0;
            int32_t L_var45 = L_var23;
            int32_t L_var16 = L_var26;
            int32_t L_var18 = L_var29;
            int32_t L_var47 = L_var33;
            (L_var36 = jmath_abs<int32_t>(this->f_b));
            if (([&]() { auto __l549 = jmath_abs<int32_t>(this->d_b); auto __r550 = L_var36; return (__l549 > __r550); }())) {
               (L_var36 = jmath_abs<int32_t>(this->d_b));
            }
            int32_t L_var48 = jmath_abs<int32_t>(this->a_b);
            if (([&]() { auto __l551 = jmath_abs<int32_t>(this->e_b); auto __r552 = L_var48; return (__l551 > __r552); }())) {
               (L_var48 = jmath_abs<int32_t>(this->e_b));
            }
            if ((jwrap32(jwint(this->f_b) + jwint(this->d_b)) > 0)) {
               (L_var36 = jshl(int32_t(L_var36),7));
               (L_var41 = 90);
               (L_var16 = L_var23);
            } else {
               if ((jwrap32(jwint(this->f_b) + jwint(this->d_b)) < 0)) {
                  (L_var36 = jshl(int32_t(L_var36),7));
                  (L_var41 = 270);
                  (L_var45 = L_var26);
               } else {
                  if ((jwrap32(jwint(this->a_b) + jwint(this->e_b)) > 0)) {
                     (L_var36 = jshl(int32_t(L_var48),7));
                     (L_var41 = 0);
                     (L_var47 = L_var29);
                  } else {
                     (L_var36 = jshl(int32_t(L_var48),7));
                     (L_var41 = 180);
                     (L_var18 = L_var33);
                  }
               }
            }
            (m::__ci(),m::i_n)->a_iiiiiiiiiii_v(1, L_var45, L_var18, L_var16, L_var47, L_var36, jdiv(int32_t(L_var36),int32_t(8)), L_var41, 0, 2000, 333);
            (this->u_i = 0);
         }
      }
   }
}
void k::__clinit() {
   __inited = true;
   j::__ci();
   t_i = ([&]() { auto __l555 = ([&]() { auto __l553 = ((k::a_Ai = Arr<int32_t>({500, 100, 300})))[0]; auto __r554 = k::a_Ai[1]; return jwrap32(jwint(__l553) + jwint(__r554)); }()); auto __r556 = k::a_Ai[2]; return jwrap32(jwint(__l555) + jwint(__r556)); }());
   u_i = k::a_Ai[2];
}
k::k() {
   (this->c_b = ((int8_t)(7)));
}
int32_t k::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   (L_var2 = j::a_Abi_i(L_var1, L_var2));
   ([&]() -> decltype(auto) { auto& __a559 = this->a_s; auto __v560 = ((int16_t)((([&]() { auto __l557 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r558 = (L_var1[(L_var2++)] & 255); return (__l557 | __r558); }())))); return (__a559 = __v560); }());
   ([&]() -> decltype(auto) { auto& __a561 = this->a_b; auto __v562 = L_var1[(L_var2++)]; return (__a561 = __v562); }());
   (this->r_i = 0);
   (this->a_z = false);
   (this->s_i = 0);
   if ((this->c_d->a_i >= 0)) {
      (this->a_z = true);
   }
   return L_var2;
}
void k::a__v() {
   (this->e_i = (-7864320));
   (this->g_i = 7864320);
   (this->f_i = (-7864320));
   (this->h_i = 7864320);
   (this->a_i = (-2621440));
   (this->b_i = 2621440);
   (this->c_i = (-2621440));
   (this->d_i = 2621440);
}
void k::b__v() {
   if (((this->r_i == 0) && ((g::__ci(),g::a_Ai)[1] == 0))) {
      ((g::__ci(),g::a_Ai)[1] = 1);
      ((m::__ci(),m::a_k) = this);
      c* L_var1 = jdown<c>(this->a__j()->a_s_j(this->a_s));
      this->a_d_v(j::a_d);
      L_var1->a_ii_v(j::a_d->c_i, jwrap32(jwint(j::a_d->f_i) + jwint(2293760)));
      (L_var1->a_z = false);
      (L_var1->b_z = false);
   }
}
void k::c__v() {
   if ((this->s_i == 0)) {
      float L_var1 = (((float)((o::__ci(),o::a_i))) * 0.001f);
      (L_var1 = (3.0f * L_var1));
      (d::__ci(),d::a_d)->a_f_v(L_var1);
      ((d::__ci(),d::a_d)->c_i = 0);
      ((d::__ci(),d::a_d)->f_i = 0);
      this->c_d->b_d_v((d::__ci(),d::a_d));
      if ((this->a_z && (this->c_d->a_i < 0))) {
         (this->c_d->a_i = 0);
         (this->c_d->d_i = 65536);
         (this->c_d->b_i = (-65536));
         (this->c_d->e_i = 0);
      }
      if (((!this->a_z) && (this->c_d->a_i > 0))) {
         (this->c_d->a_i = 0);
         (this->c_d->d_i = 65536);
         (this->c_d->b_i = 65536);
         (this->c_d->e_i = 0);
      }
      this->h__v();
   }
}
void k::e__v() {
   if ((this->s_i == 0)) {
      float L_var1 = (((float)((o::__ci(),o::a_i))) * 0.001f);
      (L_var1 = ((-3.0f) * L_var1));
      (d::__ci(),d::a_d)->a_f_v(L_var1);
      ((d::__ci(),d::a_d)->c_i = 0);
      ((d::__ci(),d::a_d)->f_i = 0);
      this->c_d->b_d_v((d::__ci(),d::a_d));
      if ((this->a_z && (this->c_d->b_i > 0))) {
         (this->c_d->a_i = 65536);
         (this->c_d->d_i = 0);
         (this->c_d->b_i = 0);
         (this->c_d->e_i = 65536);
      }
      if (((!this->a_z) && (this->c_d->b_i < 0))) {
         (this->c_d->a_i = (-65536));
         (this->c_d->d_i = 0);
         (this->c_d->b_i = 0);
         (this->c_d->e_i = 65536);
      }
      this->h__v();
   }
}
void k::f__v() {
   if ((this->s_i == 0)) {
      (this->s_i = k::t_i);
   }
}
void k::d__v() {
   j::d__v();
   (this->r_i = jwrap32(jwint(this->r_i) - jwint((o::__ci(),o::a_i))));
   if ((this->r_i < 0)) {
      (this->r_i = 0);
   }
   if ((this->s_i > 0)) {
      (this->s_i = jwrap32(jwint(this->s_i) - jwint((o::__ci(),o::a_i))));
      if (((this->s_i <= k::u_i) && ((g::__ci(),g::a_Ai)[1] == 1))) {
         c* L_var1{};
         ([&]() -> decltype(auto) { auto& __a563 = ((L_var1 = jdown<c>(this->a__j()->a_s_j(this->a_s))))->h_f; auto __v564 = 0.0f; return (__a563 = __v564); }());
         (L_var1->i_f = 0.0f);
         (L_var1->a_f = ((float)((jshr(int32_t(jwrap32(jwint(this->a_b) * jwint(this->c_d->a_i))),12)))));
         (L_var1->b_f = ((float)((jshr(int32_t(jwrap32(jwint(this->a_b) * jwint(this->c_d->d_i))),12)))));
         (L_var1->d_z = false);
         (L_var1->c_z = true);
         (L_var1->a_z = true);
         (L_var1->b_z = true);
         (L_var1->j_f = 0.0f);
         (L_var1->k_f = 0.0f);
         ((g::__ci(),g::a_Ai)[1] = 0);
         (this->r_i = 500);
         this->a_d_v(j::a_d);
         j::a_d->a_ii_v(7864320, 0);
         int32_t L_var2 = (d::__ci(),d::g_i);
         int32_t L_var3 = (d::__ci(),d::h_i);
         (L_var1->c_d->c_i = L_var2);
         (L_var1->c_d->f_i = L_var3);
         (m::__ci(),m::e_n)->a_iiiiiiiiii_v(10, L_var2, L_var3, 800, 200, this->c_d->a_i, this->c_d->d_i, 30, 800, 200);
      }
      if ((this->s_i <= 0)) {
         (this->s_i = 0);
         for (int32_t L_var5 = 0; (L_var5 < 3); (L_var5++)) {
            {
               p* L_var6 = jdown<p>((m::__ci(),m::a_Aj)[jwrap32(jwint(L_var5) + jwint(9))]);
               p* L_var7 = jdown<p>((m::__ci(),m::a_Aj)[L_var5]);
               for (int32_t L_var4 = 0; (L_var4 < L_var6->c_Ai.length()); (L_var4++)) {
                  {
                     (L_var6->c_Ai[L_var4] = L_var7->c_Ai[L_var4]);
                     (L_var6->d_Ai[L_var4] = L_var7->d_Ai[L_var4]);
                  }
               }
            }
         }
      }
   }
}
void k::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   if ((this->s_i > 0)) {
      int32_t L_var4 = jwrap32(jwint(k::t_i) - jwint(this->s_i));
      int32_t L_var5 = 0;
      int32_t L_var6 = 0;
      for (int32_t L_var7 = 0; ((L_var7 < 3) && (L_var4 >= jwrap32(jwint(L_var5) + jwint(k::a_Ai[L_var7])))); (L_var7++)) {
         {
            (L_var5 += k::a_Ai[L_var7]);
            (L_var6++);
         }
      }
      int32_t L_var19 = L_var6;
      int32_t L_var12{};
      float L_var13 = ([&]() { auto __l565 = ((float)(((L_var12 = jwrap32(jwint(L_var4) - jwint(L_var5)))))); auto __r566 = ((float)(k::a_Ai[L_var6])); return (__l565 / __r566); }());
      float L_var15 = (1.0f - L_var13);
      for (int32_t L_var17 = 0; (L_var17 < 3); (L_var17++)) {
         {
            p* L_var8 = jdown<p>((m::__ci(),m::a_Aj)[jwrap32(jwint(jwrap32(jwint(L_var19) * jwint(3))) + jwint(L_var17))]);
            p* L_var10 = jdown<p>((m::__ci(),m::a_Aj)[jwrap32(jwint(L_var17) + jwint(9))]);
            p* L_var9{};
            if ((L_var19 == 2)) {
               (L_var9 = jdown<p>((m::__ci(),m::a_Aj)[L_var17]));
            } else {
               (L_var9 = jdown<p>((m::__ci(),m::a_Aj)[jwrap32(jwint(jwrap32(jwint((jwrap32(jwint(L_var19) + jwint(1)))) * jwint(3))) + jwint(L_var17))]));
            }
            for (int32_t L_var11 = 0; (L_var11 < L_var10->c_Ai.length()); (L_var11++)) {
               {
                  (L_var10->c_Ai[L_var11] = jf2i((((((float)(L_var8->c_Ai[L_var11])) * L_var15) + (((float)(L_var9->c_Ai[L_var11])) * L_var13)))));
                  (L_var10->d_Ai[L_var11] = jf2i((((((float)(L_var8->d_Ai[L_var11])) * L_var15) + (((float)(L_var9->d_Ai[L_var11])) * L_var13)))));
               }
            }
         }
      }
   }
   this->a_d_v(j::a_d);
   (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
   int32_t L_var14 = jshr(int32_t((d::__ci(),d::a_d)->c_i),16);
   int32_t L_var16 = jshr(int32_t((d::__ci(),d::a_d)->f_i),16);
   for (int32_t L_var18 = 0; (L_var18 < 3); (L_var18++)) {
      {
         j* L_var20{};
         ([&]() -> decltype(auto) { auto& __a567 = ((L_var20 = (m::__ci(),m::a_Aj)[jwrap32(jwint(L_var18) + jwint(9))]))->c_d->c_i; auto __v568 = this->c_d->c_i; return (__a567 = __v568); }());
         (L_var20->c_d->f_i = this->c_d->f_i);
         (L_var20->c_d->a_i = this->c_d->a_i);
         (L_var20->c_d->d_i = this->c_d->d_i);
         (L_var20->c_d->b_i = this->c_d->b_i);
         (L_var20->c_d->e_i = this->c_d->e_i);
         L_var20->h__v();
         L_var20->a_GraphicsDirectGraphicsd_v(L_var1, L_var2, L_var3);
      }
   }
   (o::__ci(), o::a_iii_v(L_var14, L_var16, 48));
}
void l::__clinit() {
   __inited = true;
   j::__ci();
   x_i = 2000;
   a_Ai = Arr<int32_t>({6000, 4000, 4000, 10000});
   b_Ai = Arr<int32_t>({100, 50, 80, 150});
   c_Ai = Arr<int32_t>({50, 100, 100, 150});
}
l::l() {
   (this->c_b = ((int8_t)(10)));
}
int32_t l::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   (L_var2 = j::a_Abi_i(L_var1, L_var2));
   ([&]() -> decltype(auto) { auto& __a573 = this->c_i; auto __v574 = ([&]() { auto __l571 = (jshl(int32_t((([&]() { auto __l569 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r570 = (L_var1[(L_var2++)] & 255); return (__l569 | __r570); }()))),16)); auto __r572 = this->c_d->c_i; return jwrap32(jwint(__l571) + jwint(__r572)); }()); return (__a573 = __v574); }());
   ([&]() -> decltype(auto) { auto& __a579 = this->d_i; auto __v580 = ([&]() { auto __l577 = (jshl(int32_t((([&]() { auto __l575 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r576 = (L_var1[(L_var2++)] & 255); return (__l575 | __r576); }()))),16)); auto __r578 = this->c_d->f_i; return jwrap32(jwint(__l577) + jwint(__r578)); }()); return (__a579 = __v580); }());
   ([&]() -> decltype(auto) { auto& __a585 = this->r_i; auto __v586 = ([&]() { auto __l583 = (jshl(int32_t((([&]() { auto __l581 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r582 = (L_var1[(L_var2++)] & 255); return (__l581 | __r582); }()))),16)); auto __r584 = this->c_d->c_i; return jwrap32(jwint(__l583) + jwint(__r584)); }()); return (__a585 = __v586); }());
   ([&]() -> decltype(auto) { auto& __a591 = this->s_i; auto __v592 = ([&]() { auto __l589 = (jshl(int32_t((([&]() { auto __l587 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r588 = (L_var1[(L_var2++)] & 255); return (__l587 | __r588); }()))),16)); auto __r590 = this->c_d->f_i; return jwrap32(jwint(__l589) + jwint(__r590)); }()); return (__a591 = __v592); }());
   ([&]() -> decltype(auto) { auto& __a593 = this->a_b; auto __v594 = L_var1[(L_var2++)]; return (__a593 = __v594); }());
   (this->e_b = ((int8_t)(0)));
   (this->v_i = 0);
   (this->a_i = 0);
   (this->b_z = false);
   if ((this->c_i < this->r_i)) {
      (this->b_z = true);
   }
   (this->d_b = ((int8_t)(1)));
   (this->w_i = 2000);
   (this->f_b = ((int8_t)(1)));
   (this->b_i = 800);
   (this->a_z = false);
   if ((this->a_b == 3)) {
      (this->v_i = l::x_i);
      (this->t_i = this->c_d->c_i);
      (this->u_i = this->c_d->f_i);
      (this->c_i = this->t_i);
      (this->d_i = this->u_i);
      (this->r_i = this->t_i);
      (this->s_i = this->u_i);
   }
   return L_var2;
}
void l::a__v() {
   (this->e_i = jshl(int32_t((-l::c_Ai[this->a_b])),15));
   (this->g_i = jshl(int32_t(l::c_Ai[this->a_b]),15));
   (this->f_i = 0);
   (this->h_i = jshl(int32_t(l::b_Ai[this->a_b]),16));
}
void l::b__v() {
   this->a_d_v(j::a_d);
   int32_t L_var1 = j::a_d->c_i;
   int32_t L_var2 = (m::__ci(),m::a_c)->c_d->c_i;
   if ((((this->v_i <= 0) && (this->d_b == 0)) && (this->f_b == 1))) {
      (this->v_i = 500);
      if ((L_var1 < L_var2)) {
         ((m::__ci(),m::a_c)->f_f += 200.0f);
         ((m::__ci(),m::a_c)->g_f += 400.0f);
      } else {
         ((m::__ci(),m::a_c)->f_f += (-200.0f));
         ((m::__ci(),m::a_c)->g_f += 400.0f);
      }
      ((m::__ci(),m::a_c)->a_f = 0.0f);
      ((m::__ci(),m::a_c)->b_f = 0.0f);
   } else {
      if ((this->d_b == 1)) {
         if ((L_var1 < L_var2)) {
            ((m::__ci(),m::a_c)->f_f += 100.0f);
         } else {
            ((m::__ci(),m::a_c)->f_f += (-100.0f));
         }
         ((m::__ci(),m::a_c)->a_f = 0.0f);
         ((m::__ci(),m::a_c)->b_f = 0.0f);
      }
   }
}
void l::c__v() {
   if ((((m::__ci(),m::f_i) != 13) || ((g::__ci(),g::a_Ai)[8] != 5))) {
      {
         switch (this->a_b) {
         case 0:
         {
            if ((this->v_i <= 0)) {
               this->a_d_v(j::a_d);
               int32_t L_var1 = j::a_d->c_i;
               int32_t L_var2 = (m::__ci(),m::a_c)->c_d->c_i;
               if ((L_var1 < L_var2)) {
                  ((m::__ci(),m::a_c)->f_f += 500.0f);
               } else {
                  ((m::__ci(),m::a_c)->f_f += (-500.0f));
               }
               ((m::__ci(),m::a_c)->a_f = 0.0f);
               ((m::__ci(),m::a_c)->b_f = 0.0f);
               (this->v_i = 500);
               return;
            }
            break;
         }
         case 1:
         {
            if (((m::__ci(),m::a_c)->d_i == 1)) {
               this->f__v();
               return;
            }
            ((g::__ci(),g::a_Ai)[0] = 1);
            return;
         }
         case 2:
         {
            if ((((this->v_i <= 0) && (this->d_b == 0)) && (this->f_b == 0))) {
               (this->a_i = 0);
               (this->f_b = ((int8_t)(1)));
               (this->b_i = 200);
               return;
            }
            break;
         }
         case 3:
         {
            ((g::__ci(),g::a_Ai)[0] = 1);
            (this->c_d->c_i = this->t_i);
            (this->c_d->f_i = this->u_i);
            (this->c_i = this->t_i);
            (this->d_i = this->u_i);
            (this->r_i = this->t_i);
            (this->s_i = this->u_i);
         }
         }
      }
   }
}
void l::f__v() {
   this->a_d_v(j::a_d);
   int32_t L_var1 = j::a_d->c_i;
   int32_t L_var2 = j::a_d->f_i;
   (m::__ci(),m::g_n)->a_iiiiiii_v(10, L_var1, jwrap32(jwint(L_var2) + jwint((jshl(int32_t(l::b_Ai[this->a_b]),15)))), 370, 0, 920, 230);
   this->j__v();
   ((m::__ci(),m::a_a)->c_d->c_i = L_var1);
   ((m::__ci(),m::a_a)->c_d->f_i = jwrap32(jwint(L_var2) + jwint(1966080)));
   (m::__ci(),m::a_a)->b_d->a_d_v(this->c_d);
   (m::__ci(),m::a_a)->k__v();
   (m::__ci(),m::a_a)->b_d->c_d_v((m::__ci(),m::a_a)->d_d);
}
void l::e__v() {
   {
      switch (this->a_b) {
      case 0:
      {
         l::g__v();
         this->f__v();
         return;
      }
      case 1:
      case 3:
      {
         return;
      }
      case 2:
      {
         l::g__v();
         this->f__v();
      }
      }
   }
}
void l::g__v() {
   if (((m::__ci(),m::a_c)->b_f < 0.0f)) {
      ((m::__ci(),m::a_c)->b_f = ((-(m::__ci(),m::a_c)->b_f) * 0.5f));
      ((m::__ci(),m::a_c)->a_f *= 0.7f);
   } else {
      ((m::__ci(),m::a_c)->a_f = ((-(m::__ci(),m::a_c)->a_f) * 0.5f));
      ((m::__ci(),m::a_c)->b_f *= 0.7f);
   }
}
void l::d__v() {
   this->h__v();
   j::d__v();
   if ((((m::__ci(),m::f_i) != 13) || ((g::__ci(),g::a_Ai)[8] != 5))) {
      int32_t L_var1 = (o::__ci(),o::a_i);
      int32_t L_var2 = this->c_d->c_i;
      int32_t L_var3 = this->c_d->f_i;
      if ((this->v_i > 0)) {
         (this->v_i -= L_var1);
         if ((this->v_i <= 0)) {
            (this->v_i = 0);
            if ((this->a_b == 3)) {
               (this->v_i = l::x_i);
               (this->r_i = this->c_i);
               (this->s_i = this->d_i);
               int32_t L_var6 = jwrap32(jwint(this->r_i) - jwint(L_var2));
               int32_t L_var7 = jwrap32(jwint(this->s_i) - jwint(L_var3));
               float L_var8 = ((float)((jshr(int32_t(L_var6),16))));
               float L_var9 = ((float)((jshr(int32_t(L_var7),16))));
               int32_t L_var26 = jf2i(((std::sqrt(((double)((((L_var8 * L_var8) + (L_var9 * L_var9)))))) * 65536.0)));
               int32_t L_var32{};
               if (([&]() { auto __l595 = ((L_var32 = jwrap32(jwint((jshl(int32_t(l::x_i),1))) * jwint(l::a_Ai[this->a_b])))); auto __r596 = L_var26; return (__l595 > __r596); }())) {
                  double L_var12 = (((double)(L_var32)) / ((double)(L_var26)));
                  (this->r_i += jf2i(((((double)(L_var6)) * ((L_var12 - 1.0))))));
                  (this->s_i += jf2i(((((double)(L_var7)) * ((L_var12 - 1.0))))));
               }
               (this->c_i = (m::__ci(),m::a_c)->c_d->c_i);
               (this->d_i = (m::__ci(),m::a_c)->c_d->f_i);
            }
         }
      }
      if ((this->a_b == 3)) {
         int32_t L_var22 = this->r_i;
         int32_t L_var24 = this->s_i;
         int32_t L_var4 = jwrap32(jwint(L_var22) - jwint(L_var2));
         int32_t L_var5 = jwrap32(jwint(L_var24) - jwint(L_var3));
         float L_var27 = ((float)((jshr(int32_t(L_var4),16))));
         float L_var33 = ((float)((jshr(int32_t(L_var5),16))));
         int32_t L_var28{};
         if ((((L_var28 = jf2i(((std::sqrt(((double)((((L_var27 * L_var27) + (L_var33 * L_var33)))))) * 65536.0))))) != 0)) {
            int32_t L_var34{};
            double L_var38 = ([&]() { auto __l597 = ((double)(((L_var34 = jwrap32(jwint(L_var1) * jwint(l::a_Ai[this->a_b])))))); auto __r598 = ((double)(L_var28)); return (__l597 / __r598); }());
            (L_var2 += jf2i(((((double)(L_var4)) * L_var38))));
            (L_var3 += jf2i(((((double)(L_var5)) * L_var38))));
         }
      } else {
         if ((this->a_b == 2)) {
            if ((this->w_i > 0)) {
               (this->w_i -= L_var1);
               if ((this->w_i <= 0)) {
                  if ((this->d_b == 0)) {
                     (this->d_b = ((int8_t)(1)));
                     (this->w_i = 2000);
                     (this->f_b = ((int8_t)(1)));
                     (this->b_i = 800);
                  } else {
                     (this->d_b = ((int8_t)(0)));
                     (this->w_i = 5000);
                     (this->f_b = ((int8_t)(2)));
                     (this->b_i = 800);
                     (this->a_z = true);
                  }
               }
            }
            if ((this->f_b == 1)) {
               (this->a_i += L_var1);
               if ((this->a_i >= this->b_i)) {
                  if ((this->d_b == 0)) {
                     (this->f_b = ((int8_t)(2)));
                     (this->b_i = 200);
                  }
                  (this->a_i = this->b_i);
               }
            } else {
               if ((this->f_b == 2)) {
                  (this->a_i -= L_var1);
                  if ((this->a_i <= 0)) {
                     (this->f_b = ((int8_t)(0)));
                     (this->a_i = 0);
                     (this->a_z = false);
                  }
               }
            }
         }
         int32_t L_var23{};
         int32_t L_var25{};
         int32_t L_var29{};
         if ((this->e_b == 0)) {
            (L_var23 = this->c_i);
            (L_var25 = this->d_i);
            (L_var29 = this->r_i);
         } else {
            (L_var23 = this->r_i);
            (L_var25 = this->s_i);
            (L_var29 = this->c_i);
         }
         if ((((this->a_b == 0) && (jmath_abs<int32_t>(jwrap32(jwint(L_var2) - jwint(L_var23))) > 4587520)) && (jmath_abs<int32_t>(jwrap32(jwint(L_var2) - jwint(L_var29))) > 4587520))) {
            this->a_d_v(j::a_d);
            int32_t L_var35 = j::a_d->c_i;
            (L_var29 = (m::__ci(),m::a_c)->c_d->c_i);
            if (((jmath_abs<int32_t>(jwrap32(jwint((m::__ci(),m::a_c)->c_d->c_i) - jwint(L_var35))) < 7864320) && ((((L_var35 < L_var29) && (L_var23 < L_var2)) || ((L_var35 > L_var29) && (L_var23 > L_var2)))))) {
               if ((this->e_b == 0)) {
                  (L_var23 = this->r_i);
                  (L_var25 = this->s_i);
                  (this->e_b = ((int8_t)(1)));
               } else {
                  (L_var23 = this->c_i);
                  (L_var25 = this->d_i);
                  (this->e_b = ((int8_t)(0)));
               }
            }
         }
         int32_t L_var18 = jwrap32(jwint(L_var23) - jwint(L_var2));
         int32_t L_var20 = jwrap32(jwint(L_var25) - jwint(L_var3));
         float L_var36 = ((float)((jshr(int32_t(L_var18),16))));
         float L_var31 = ((float)((jshr(int32_t(L_var20),16))));
         int32_t L_var37 = jf2i(((std::sqrt(((double)((((L_var36 * L_var36) + (L_var31 * L_var31)))))) * 65536.0)));
         bool L_var39 = false;
         bool L_var13 = false;
         if ((L_var37 != 0)) {
            int32_t L_var17{};
            double L_var15 = ([&]() { auto __l599 = ((double)(((L_var17 = jwrap32(jwint(L_var1) * jwint(l::a_Ai[this->a_b])))))); auto __r600 = ((double)(L_var37)); return (__l599 / __r600); }());
            (L_var18 = jf2i(((((double)(L_var18)) * L_var15))));
            (L_var20 = jf2i(((((double)(L_var20)) * L_var15))));
            (L_var2 += L_var18);
            (L_var3 += L_var20);
            if ((((L_var18 >= 0) && (L_var2 >= L_var23)) || ((L_var18 <= 0) && (L_var2 <= L_var23)))) {
               (L_var2 = L_var23);
               (L_var39 = true);
            }
            if ((((L_var20 >= 0) && (L_var3 >= L_var25)) || ((L_var20 <= 0) && (L_var3 <= L_var25)))) {
               (L_var3 = L_var25);
               (L_var13 = true);
            }
         }
         if (((L_var39 && L_var13) || (L_var37 == 0))) {
            (L_var2 = L_var23);
            (L_var3 = L_var25);
            if ((this->e_b == 0)) {
               (this->e_b = ((int8_t)(1)));
            } else {
               (this->e_b = ((int8_t)(0)));
            }
         }
      }
      if (((this->a_b != 2) || (((this->a_b == 2) && (this->d_b == 0)) && (this->f_b == 0)))) {
         (this->b_z = true);
         if ((this->c_d->c_i < L_var2)) {
            (this->b_z = false);
         }
         (this->c_d->c_i = L_var2);
         (this->c_d->f_i = L_var3);
         (this->e_z = true);
         (this->f_z = true);
      }
   }
}
void l::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   this->a_d_v(j::a_d);
   (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
   int32_t L_var11 = jshr(int32_t((d::__ci(),d::a_d)->c_i),16);
   int32_t L_var12 = jshr(int32_t((d::__ci(),d::a_d)->f_i),16);
   {
      int32_t L_var10{};
      int32_t L_var9{};
      switch (this->a_b) {
      case 0:
      {
         L_var10 = jrem(int32_t(jdiv(int32_t((m::__ci(),m::b_i)),int32_t(50))),int32_t(6));
         (o::__ci(), o::b_iiii_v(L_var11, L_var12, 467, L_var10));
         return;
      }
      case 1:
      {
         if (this->b_z) {
            (o::__ci(), o::a_iii_v(L_var11, L_var12, (-41)));
            return;
         }
         (o::__ci(), o::a_iii_v(L_var11, L_var12, (-42)));
         return;
      }
      case 2:
      {
         if ((this->f_b != 0)) {
            int32_t L_var4 = L_var1->getClipX();
            int32_t L_var5 = L_var1->getClipY();
            int32_t L_var6 = L_var1->getClipWidth();
            int32_t L_var7 = L_var1->getClipHeight();
            int32_t L_var8{};
            if (([&]() { auto __l601 = ((L_var8 = jwrap32(jwint(L_var12) - jwint(L_var5)))); auto __r602 = L_var7; return (__l601 > __r602); }())) {
               (L_var8 = L_var7);
            }
            L_var1->setClip(L_var4, L_var5, L_var6, L_var8);
            (L_var8 = jdiv(int32_t(jwrap32(jwint(this->a_i) * jwint(61))),int32_t(this->b_i)));
            if (this->b_z) {
               (o::__ci(), o::a_iii_v(L_var11, jwrap32(jwint(jwrap32(jwint(L_var12) + jwint(61))) - jwint(L_var8)), 189));
            } else {
               (o::__ci(), o::a_iii_v(L_var11, jwrap32(jwint(jwrap32(jwint(L_var12) + jwint(61))) - jwint(L_var8)), 194));
            }
            L_var1->setClip(L_var4, L_var5, L_var6, L_var7);
         }
         if ((this->f_b == 0)) {
            (L_var9 = jrem(int32_t(jdiv(int32_t((m::__ci(),m::a_i)),int32_t(150))),int32_t(4)));
         } else {
            (L_var9 = 0);
         }
         (o::__ci(), o::b_iiii_v(L_var11, L_var12, 504, L_var9));
         return;
      }
      case 3:
      {
         (o::__ci(), o::a_iii_v(L_var11, L_var12, (-28)));
      }
      }
   }
}
void m::__clinit() {
   __inited = true;
   a_As = Arr<int16_t>({((int16_t)(49)), ((int16_t)(45)), ((int16_t)(44)), ((int16_t)(47)), ((int16_t)(50)), ((int16_t)(46)), ((int16_t)(48)), ((int16_t)(36)), ((int16_t)(86)), ((int16_t)(19)), ((int16_t)(18)), ((int16_t)(17)), ((int16_t)(4)), ((int16_t)(12)), ((int16_t)(13)), ((int16_t)(11)), ((int16_t)(14)), ((int16_t)(15)), ((int16_t)(85)), ((int16_t)(82)), ((int16_t)(37)), ((int16_t)(87)), ((int16_t)(38)), ((int16_t)(39)), ((int16_t)(89)), ((int16_t)(2)), ((int16_t)(3)), ((int16_t)(35)), ((int16_t)(16)), ((int16_t)(0)), ((int16_t)(1)), ((int16_t)(20)), ((int16_t)(24)), ((int16_t)(25)), ((int16_t)(32)), ((int16_t)(26)), ((int16_t)(27)), ((int16_t)(28)), ((int16_t)(29)), ((int16_t)(33)), ((int16_t)(30)), ((int16_t)(31)), ((int16_t)(21)), ((int16_t)(22)), ((int16_t)(34)), ((int16_t)(23)), ((int16_t)(88)), ((int16_t)(83)), ((int16_t)(84)), ((int16_t)(5)), ((int16_t)(6)), ((int16_t)(8)), ((int16_t)(7)), ((int16_t)(42)), ((int16_t)(9)), ((int16_t)(10)), ((int16_t)(41)), ((int16_t)(43)), ((int16_t)(56)), ((int16_t)(57)), ((int16_t)(58)), ((int16_t)(65)), ((int16_t)(59)), ((int16_t)(60)), ((int16_t)(61)), ((int16_t)(62)), ((int16_t)(63)), ((int16_t)(64)), ((int16_t)(66)), ((int16_t)(67)), ((int16_t)(68)), ((int16_t)(69)), ((int16_t)(70)), ((int16_t)(71)), ((int16_t)(72)), ((int16_t)(73)), ((int16_t)(74)), ((int16_t)(75)), ((int16_t)(76)), ((int16_t)(77)), ((int16_t)(78)), ((int16_t)(79)), ((int16_t)(80)), ((int16_t)(51)), ((int16_t)(52)), ((int16_t)(53)), ((int16_t)(54)), ((int16_t)(55)), ((int16_t)(81)), ((int16_t)(40)), ((int16_t)(90))});
   e_z = (q::__ci(), q::a_i_String(90)).equals(JS(u"1"));
   a_Ab = Arr<int8_t>({((int8_t)(10)), ((int8_t)(10)), ((int8_t)(10))});
   b_Ab = Arr<int8_t>({((int8_t)(11)), ((int8_t)(11)), ((int8_t)(11))});
   JString L_var0{};
   if (((((L_var0 = (o::__ci(),o::a_MIDlet)->getAppProperty(JS(u"Cheats")))) != nullptr) && L_var0.equals(JS(u"On")))) {
      (m::f_z = true);
   } else {
      (m::f_z = false);
   }
   (m::c_As = Arr<int16_t>({((int16_t)(314)), ((int16_t)(315)), ((int16_t)(389))}));
   (m::a_Random = JRandom::make(JSystem::currentTimeMillis()));
   (m::k_i = 0);
   (m::l_i = 0);
   (m::m_i = 0);
   (m::n_i = 0);
   (m::o_i = 0);
   (m::a_Af = Arr<float>({0.937f, 0.969f, 0.659f, 0.937f, 1.412f, 0.969f, 2.121f, 1.298f, 1.298f, 1.011f, 1.298f, 1.921f, 1.298f, 0.712f, 1.195f}));
   (m::c_Ai = Arr<int32_t>({4, 60, 9, 200, 14, 400}));
   (m::d_Ai = Arr<int32_t>({3, 8}));
   (m::d_As = Arr<int16_t>({((int16_t)(30)), ((int16_t)(29)), ((int16_t)(26)), ((int16_t)(30)), ((int16_t)(28)), ((int16_t)(26)), ((int16_t)(30)), ((int16_t)(25)), ((int16_t)(21)), ((int16_t)(30)), ((int16_t)(25)), ((int16_t)(20)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(28)), ((int16_t)(25)), ((int16_t)(30)), ((int16_t)(28)), ((int16_t)(22)), ((int16_t)(30)), ((int16_t)(27)), ((int16_t)(20)), ((int16_t)(30)), ((int16_t)(27)), ((int16_t)(24)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(29)), ((int16_t)(27)), ((int16_t)(30)), ((int16_t)(28)), ((int16_t)(19)), ((int16_t)(30)), ((int16_t)(25)), ((int16_t)(20)), ((int16_t)(30)), ((int16_t)(25)), ((int16_t)(20)), ((int16_t)(30)), ((int16_t)(30)), ((int16_t)(30))}));
   (m::e_As = Arr<int16_t>({((int16_t)(30)), ((int16_t)(40)), ((int16_t)(50)), ((int16_t)(36)), ((int16_t)(45)), ((int16_t)(55)), ((int16_t)(35)), ((int16_t)(40)), ((int16_t)(48)), ((int16_t)(32)), ((int16_t)(42)), ((int16_t)(50)), ((int16_t)(9999)), ((int16_t)(9999)), ((int16_t)(9999)), ((int16_t)(34)), ((int16_t)(45)), ((int16_t)(60)), ((int16_t)(75)), ((int16_t)(85)), ((int16_t)(95)), ((int16_t)(42)), ((int16_t)(46)), ((int16_t)(55)), ((int16_t)(45)), ((int16_t)(55)), ((int16_t)(65)), ((int16_t)(9999)), ((int16_t)(9999)), ((int16_t)(9999)), ((int16_t)(45)), ((int16_t)(50)), ((int16_t)(58)), ((int16_t)(60)), ((int16_t)(70)), ((int16_t)(80)), ((int16_t)(48)), ((int16_t)(54)), ((int16_t)(60)), ((int16_t)(24)), ((int16_t)(34)), ((int16_t)(44)), ((int16_t)(9999)), ((int16_t)(9999)), ((int16_t)(9999))}));
   (m::f_As = newArr<int16_t>(60));
   (m::g_As = Arr<int16_t>({((int16_t)(359)), ((int16_t)(363)), ((int16_t)(364)), ((int16_t)(365)), ((int16_t)(328)), ((int16_t)(366)), ((int16_t)(367)), ((int16_t)(368)), ((int16_t)(369)), ((int16_t)(329)), ((int16_t)(370)), ((int16_t)(360)), ((int16_t)(361)), ((int16_t)(362)), ((int16_t)(330))}));
   (m::h_As = Arr<int16_t>({((int16_t)(20)), ((int16_t)(24)), ((int16_t)(25)), ((int16_t)(26)), ((int16_t)(32)), ((int16_t)(27)), ((int16_t)(28)), ((int16_t)(29)), ((int16_t)(30)), ((int16_t)(33)), ((int16_t)(31)), ((int16_t)(21)), ((int16_t)(22)), ((int16_t)(23)), ((int16_t)(34))}));
   (m::i_As = Arr<int16_t>({((int16_t)(388))}));
   (m::j_As = Arr<int16_t>({((int16_t)(251))}));
   (m::k_As = Arr<int16_t>({((int16_t)(252))}));
   (m::l_As = newArr<int16_t>(0));
   (m::m_As = Arr<int16_t>({((int16_t)(373))}));
   (m::n_As = Arr<int16_t>({((int16_t)(161))}));
   (m::o_As = Arr<int16_t>({((int16_t)(159)), ((int16_t)(160))}));
   (m::p_As = newArr<int16_t>(0));
   (m::q_As = Arr<int16_t>({((int16_t)(352))}));
   (m::r_As = Arr<int16_t>({((int16_t)(113))}));
   (m::s_As = Arr<int16_t>({((int16_t)(114))}));
   (m::t_As = Arr<int16_t>({((int16_t)(353))}));
   (m::u_As = Arr<int16_t>({((int16_t)(388)), ((int16_t)(373)), ((int16_t)(145)), ((int16_t)(313)), ((int16_t)(265)), ((int16_t)(157)), ((int16_t)(174)), ((int16_t)(55)), ((int16_t)(345)), ((int16_t)(243)), ((int16_t)(78)), ((int16_t)(317)), ((int16_t)(176)), ((int16_t)(267))}));
   (m::v_As = Arr<int16_t>({((int16_t)(39)), ((int16_t)(40)), ((int16_t)(41)), ((int16_t)(42)), ((int16_t)(51)), ((int16_t)(43)), ((int16_t)(44)), ((int16_t)(45)), ((int16_t)(46)), ((int16_t)(52)), ((int16_t)(47)), ((int16_t)(48)), ((int16_t)(49)), ((int16_t)(50)), ((int16_t)(53)), ((int16_t)(54))}));
   (m::w_i = 0);
   (m::e_i = 0);
   (m::x_i = (o::__ci(),o::b_i));
   (m::y_i = (o::__ci(),o::c_i));
   (m::q_i = 129);
   (m::r_i = 40);
   (m::s_i = 5);
   (m::t_i = 56);
   (m::u_i = 20);
   (m::v_i = 40);
   (m::b_As = newArr<int16_t>(360));
   m::a__v();
   (m::e_Ai = Arr<int32_t>({536}));
   (m::f_Ai = Arr<int32_t>({526, 516, 531, 521}));
   (m::g_Ai = Arr<int32_t>({390, 420}));
   (m::h_Ai = Arr<int32_t>({420, 426}));
   (m::i_Ai = Arr<int32_t>({414, 396, 420}));
   (m::j_Ai = Arr<int32_t>({420, 426, 402, 408}));
   (m::k_Ai = Arr<int32_t>({420, 426}));
   (m::l_Ai = Arr<int32_t>({390, 414, 396}));
   (m::c_n = (n::__ci(), new n(150, 0, 80, 0, 0, 0, 1, m::e_Ai, 4000, 7)));
   (m::b_n = (n::__ci(), new n(20, 0, (-200), 0, 0, 0, 0, m::f_Ai, 800, 7)));
   (m::e_n = (n::__ci(), new n(10, 0, 0, 0, 0, 30, 2, m::g_Ai, 800, (-1))));
   (m::f_n = (n::__ci(), new n(50, 0, 0, 0, 0, 85, 3, m::h_Ai, 540, (-2))));
   (m::g_n = (n::__ci(), new n(50, 0, 0, 0, 0, 35, 4, m::i_Ai, 1840, (-3))));
   (m::a_n = (n::__ci(), new n(20, 0, 0, 0, 0, 35, 4, m::j_Ai, 1840, (-4))));
   (m::d_n = (n::__ci(), new n(10, 0, 0, 0, 0, 0, 6, m::k_Ai, 1000, (-5))));
   (m::h_n = (n::__ci(), new n(24, 0, 0, 0, 0, 35, 4, m::l_Ai, 2040, (-6))));
   (m::m_Ai = Arr<int32_t>({437, 432}));
   (m::i_n = (n::__ci(), new n(150, 0, 0, 0, 0, 0, 7, m::m_Ai, 2000, 15)));
   (m::n_Ai = newArr<int32_t>(5));
   (m::a_AString = nullptr);
   (m::i_z = false);
   (m::A_i = 17);
   (m::j_z = false);
   (m::o_Ai = Arr<int32_t>({7}));
   (m::p_Ai = Arr<int32_t>({1}));
   (m::q_Ai = Arr<int32_t>({3000}));
   (m::r_Ai = Arr<int32_t>({16777215}));
   (m::c_z = false);
   (m::s_Ai = newArr<int32_t>(10));
   (m::t_Ai = newArr<int32_t>(10));
   (m::u_Ai = newArr<int32_t>(10));
   (m::v_Ai = newArr<int32_t>(4));
   (m::w_Ai = newArr<int32_t>(4));
   (m::w_As = Arr<int16_t>({((int16_t)(90)), ((int16_t)(91)), ((int16_t)(92)), ((int16_t)(93)), ((int16_t)(94)), ((int16_t)(95)), ((int16_t)(96)), ((int16_t)(97)), ((int16_t)(98)), ((int16_t)(99))}));
}
m::m() {
   this->a_h = nullptr;
   this->b_h = (h::__ci(), new h());
   this->j_i = 1;
   this->B_i = 0;
   this->k_z = false;
   this->n_z = false;
   this->o_z = false;
   this->p_z = false;
   this->J_i = (-1);
   this->K_i = (-1);
   this->q_z = false;
}
int32_t m::a__i() {
   int32_t L_var0 = 0;
   if ((m::a_i_z(m::d_Ai[0]) || ((m::f_i == m::d_Ai[0]) && ((g::__ci(),g::a_Ai)[2] > 0)))) {
      (L_var0 = 1);
   }
   if ((m::a_i_z(m::d_Ai[1]) || ((m::f_i == m::d_Ai[1]) && ((g::__ci(),g::a_Ai)[2] > 0)))) {
      (L_var0 = 2);
   }
   return L_var0;
}
bool m::b_i_z(int32_t L_var0) {
   return (m::f_As[jwrap32(jwint((jshl(int32_t(L_var0),2))) + jwint(1))] > 0);
}
bool m::a_i_z(int32_t L_var0) {
   (L_var0 = jshl(int32_t(L_var0),2));
   return ((m::f_As[jwrap32(jwint(L_var0) + jwint(1))] > 0) && (m::f_As[jwrap32(jwint(L_var0) + jwint(1))] < 9999));
}
void m::a_isss_v(int32_t L_var0, int16_t L_var1, int16_t L_var2, int16_t L_var3) {
   (L_var0 = jshl(int32_t(L_var0),2));
   if ((L_var1 > m::f_As[L_var0])) {
      (m::f_As[L_var0] = L_var1);
   }
   if ((L_var2 < m::f_As[jwrap32(jwint(L_var0) + jwint(1))])) {
      (m::f_As[jwrap32(jwint(L_var0) + jwint(1))] = L_var2);
   }
   if ((L_var3 > m::f_As[jwrap32(jwint(L_var0) + jwint(2))])) {
      (m::f_As[jwrap32(jwint(L_var0) + jwint(2))] = L_var3);
   }
   if ((L_var3 > m::f_As[jwrap32(jwint(L_var0) + jwint(3))])) {
      (m::f_As[jwrap32(jwint(L_var0) + jwint(3))] = L_var3);
   }
}
void m::e_i_v(int32_t L_var0) {
   if ((m::f_As[jwrap32(jwint((jshl(int32_t(L_var0),2))) + jwint(1))] == 0)) {
      (m::f_As[jwrap32(jwint((jshl(int32_t(L_var0),2))) + jwint(1))] = ((int16_t)(9999)));
   }
}
void m::f_i_v(int32_t L_var0) {
   (L_var0 = jshl(int32_t(L_var0),2));
   if (((m::f_As[jwrap32(jwint(L_var0) + jwint(1))] == 0) || (m::f_As[jwrap32(jwint(L_var0) + jwint(1))] == 9999))) {
      (m::f_As[jwrap32(jwint(L_var0) + jwint(1))] = ((int16_t)(300)));
   }
}
bool m::c_i_z(int32_t L_var0) {
   for (int32_t L_var1 = 0; (L_var1 < m::c_Ai.length()); (L_var1 += 2)) {
      {
         if ((L_var0 == m::c_Ai[L_var1])) {
            return true;
         }
      }
   }
   return false;
}
int32_t m::c__i() {
   int32_t L_var0 = 0;
   for (int32_t L_var1 = 0; (L_var1 < 15); (L_var1++)) {
      {
         (L_var0 += m::f_As[jshl(int32_t(L_var1),2)]);
      }
   }
   return L_var0;
}
bool m::a__z() {
   for (int32_t L_var0 = 0; (L_var0 < 15); (L_var0++)) {
      {
         int32_t L_var1 = jshl(int32_t(L_var0),2);
         if ((m::f_As[L_var1] < m::d_As[jwrap32(jwint(L_var0) * jwint(3))])) {
            return false;
         }
         if ((m::f_As[jwrap32(jwint(L_var1) + jwint(1))] > m::e_As[jwrap32(jwint(L_var0) * jwint(3))])) {
            return false;
         }
      }
   }
   return true;
}
void m::a__v() {
   int32_t L_var0 = 20520;
   int32_t L_var1 = 0;
   int32_t L_var2 = 0;
   while ((L_var1 < 360)) {
      {
         int32_t L_var3 = jdiv(int32_t(L_var2),int32_t(57));
         (L_var0 -= L_var3);
         (L_var2 += jdiv(int32_t(L_var0),int32_t(57)));
         ([&]() -> decltype(auto) { auto& __a603 = m::b_As[(L_var1++)]; auto __v604 = ((int16_t)(L_var3)); return (__a603 = __v604); }());
      }
   }
}
void m::g_i_v(int32_t L_var1) {
   this->b_h->a__v();
   this->b_h->b_i_v(0);
   this->b_h->b_i_v(1);
   (this->b_h->b_Ai = nullptr);
   (this->b_h->a_Ai = nullptr);
   (this->b_h->a_i = L_var1);
   this->b_h->a_ii_v(9, (-2));
   this->b_h->b_ii_v(13, (-2));
   {
      bool L_var8{};
      Arr<JString> L_var6{};
      f* L_var10{};
      switch (L_var1) {
      case 10:
      {
         this->b_h->d_i_v(36);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(6, m::r_i);
         this->b_h->b_ii_v(7, m::s_i);
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::t_i)));
         this->b_h->b_ii_v(11, jwrap32(jwint(([&]() { auto __l605 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); auto __r606 = (jshl(int32_t(m::u_i),1)); return jwrap32(jwint(__l605) - jwint(__r606)); }())) + jwint(4)));
         this->b_h->b_ii_v(9, jwrap32(jwint(([&]() { auto __l609 = (jshr(int32_t(([&]() { auto __l607 = (o::__ci(),o::b_i); auto __r608 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); return jwrap32(jwint(__l607) - jwint(__r608)); }())),1)); auto __r610 = m::u_i; return jwrap32(jwint(__l609) + jwint(__r610)); }())) - jwint(2)));
         this->b_h->a_ii_v(3, 0);
         this->b_h->a_ii_v(2, 32);
         this->b_h->b_ii_v(14, jshl(int32_t((o::__ci(), o::a_i_i((-3)))),1));
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(19)), (-1), 1);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(44)), 0, 17, true);
         L_var8 = false;
         for (int32_t L_var17 = 0; (L_var17 < 15); (L_var17++)) {
            {
               if ((m::f_As[jwrap32(jwint((jshl(int32_t(L_var17),2))) + jwint(3))] > 0)) {
                  (L_var8 = true);
               }
            }
         }
         if (L_var8) {
            Arr<JString> L_var20 = newArr<JString>(1);
            for (int32_t L_var9 = 0; (L_var9 < 15); (L_var9++)) {
               {
                  JString L_var4 = JS(u"0");
                  if ((m::f_As[jwrap32(jwint((jshl(int32_t(L_var9),2))) + jwint(3))] > 0)) {
                     (L_var4 = jcat(JS(u""),(int32_t)(m::f_As[jwrap32(jwint((jshl(int32_t(L_var9),2))) + jwint(3))])));
                  }
                  JString L_var18{};
                  if (m::c_i_z(L_var9)) {
                     ([&]() -> decltype(auto) { auto& __a611 = L_var20[0]; auto __v612 = m::a_i_String(L_var9); return (__a611 = __v612); }());
                     (L_var18 = (q::__ci(), q::a_iAString_String(16, L_var20)));
                  } else {
                     ([&]() -> decltype(auto) { auto& __a613 = L_var20[0]; auto __v614 = m::a_i_String(L_var9); return (__a613 = __v614); }());
                     (L_var18 = (q::__ci(), q::a_iAString_String(35, L_var20)));
                  }
                  int32_t L_var5 = 89;
                  if ((L_var9 == 0)) {
                     (L_var5 = (-1));
                  }
                  this->b_h->a_f_v((f::__ci(), new f(jcat(jcat(L_var18,JS(u"\n")),L_var4), L_var5, this->b_h, (-1))));
               }
            }
         } else {
            this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p615 = (q::__ci(), q::a_i_String(4)); auto __p616 = (-1); auto __p617 = this->b_h; auto __p618 = (-1); return (f::__ci(), new f(__p615, __p616, __p617, __p618)); }()));
         }
      }
      case 11:
      case 12:
      case 13:
      case 14:
      case 15:
      case 16:
      case 19:
      case 21:
      case 23:
      case 26:
      case 27:
      default:
      {
         break;
      }
      case 17:
      {
         this->b_h->d_i_v(37);
         this->b_h->a_ii_v(9, (-2));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->a_ii_v(5, 256);
         this->b_h->b_ii_v(6, m::q_i);
         this->b_h->b_ii_v(5, 128);
         this->b_h->a_ii_v(18, 16742400);
         this->b_h->a_Stringii_v(JS(u""), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(49)), 0, (-2), true);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(45)), 0, 9, false);
         if (m::b_i_z(1)) {
            this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p619 = (q::__ci(), q::a_i_String(17)); auto __p620 = (-1); auto __p621 = this->b_h; auto __p622 = 18; return (f::__ci(), new f(__p619, __p620, __p621, __p622)); }()));
            this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p623 = (q::__ci(), q::a_i_String(36)); auto __p624 = (-1); auto __p625 = this->b_h; auto __p626 = 20; return (f::__ci(), new f(__p623, __p624, __p625, __p626)); }()));
         } else {
            this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p627 = (q::__ci(), q::a_i_String(36)); auto __p628 = (-1); auto __p629 = this->b_h; auto __p630 = 18; return (f::__ci(), new f(__p627, __p628, __p629, __p630)); }()));
            (m::k_i = 0);
         }
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p631 = (q::__ci(), q::a_i_String(19)); auto __p632 = (-1); auto __p633 = this->b_h; auto __p634 = 10; return (f::__ci(), new f(__p631, __p632, __p633, __p634)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p635 = (q::__ci(), q::a_i_String(18)); auto __p636 = (-1); auto __p637 = this->b_h; auto __p638 = 22; return (f::__ci(), new f(__p635, __p636, __p637, __p638)); }()));
         this->b_h->a_i_v(m::o_i);
         break;
      }
      case 18:
      {
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(49)), 0, 7, true);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(44)), 0, 17, true);
         m::a_h_v(this->b_h);
         break;
      }
      case 20:
      {
         this->b_h->d_i_v(37);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->b_ii_v(6, m::r_i);
         this->b_h->b_ii_v(7, m::s_i);
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(86)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(50)), 0, 11, false);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(46)), 0, 17, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p639 = (q::__ci(), q::a_i_String(2)); auto __p640 = (-1); auto __p641 = this->b_h; auto __p642 = (-1); return (f::__ci(), new f(__p639, __p640, __p641, __p642)); }()));
         break;
      }
      case 22:
      {
         this->b_h->d_i_v(36);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(6, m::r_i);
         this->b_h->b_ii_v(7, m::s_i);
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::t_i)));
         this->b_h->b_ii_v(11, jwrap32(jwint(([&]() { auto __l643 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); auto __r644 = (jshl(int32_t(m::u_i),1)); return jwrap32(jwint(__l643) - jwint(__r644)); }())) + jwint(4)));
         this->b_h->b_ii_v(9, jwrap32(jwint(([&]() { auto __l647 = (jshr(int32_t(([&]() { auto __l645 = (o::__ci(),o::b_i); auto __r646 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); return jwrap32(jwint(__l645) - jwint(__r646)); }())),1)); auto __r648 = m::u_i; return jwrap32(jwint(__l647) + jwint(__r648)); }())) - jwint(2)));
         this->b_h->a_ii_v(3, 0);
         this->b_h->a_ii_v(2, 32);
         this->b_h->b_ii_v(14, jshl(int32_t((o::__ci(), o::a_i_i((-3)))),1));
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(18)), (-1), 1);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(44)), 0, 17, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p649 = (q::__ci(), q::a_i_String(12)); auto __p650 = (-1); auto __p651 = this->b_h; auto __p652 = (-1); return (f::__ci(), new f(__p649, __p650, __p651, __p652)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p653 = (q::__ci(), q::a_i_String(13)); auto __p654 = 102; auto __p655 = this->b_h; auto __p656 = (-1); return (f::__ci(), new f(__p653, __p654, __p655, __p656)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p657 = (q::__ci(), q::a_i_String(11)); auto __p658 = (-1); auto __p659 = this->b_h; auto __p660 = (-1); return (f::__ci(), new f(__p657, __p658, __p659, __p660)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p661 = (q::__ci(), q::a_i_String(14)); auto __p662 = 371; auto __p663 = this->b_h; auto __p664 = (-1); return (f::__ci(), new f(__p661, __p662, __p663, __p664)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p665 = (q::__ci(), q::a_i_String(15)); auto __p666 = 372; auto __p667 = this->b_h; auto __p668 = (-1); return (f::__ci(), new f(__p665, __p666, __p667, __p668)); }()));
         break;
      }
      case 24:
      {
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(82)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(50)), 0, 9, false);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(46)), 0, 17, true);
         break;
      }
      case 25:
      {
         this->b_h->d_i_v(37);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->a_ii_v(5, 256);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(11, jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(m::v_i))) + jwint(4)));
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::b_i)) - jwint(m::v_i)));
         this->b_h->b_ii_v(4, 64);
         this->b_h->b_ii_v(3, 32);
         this->b_h->b_ii_v(5, 128);
         this->b_h->a_ii_v(18, 16742400);
         this->b_h->b_ii_v(2, 0);
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(85)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(49)), 0, (-2), true);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(48)), 0, 30, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p669 = (q::__ci(), q::a_i_String(38)); auto __p670 = (-1); auto __p671 = this->b_h; auto __p672 = 8; return (f::__ci(), new f(__p669, __p670, __p671, __p672)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p673 = (q::__ci(), q::a_i_String(37)); auto __p674 = (-1); auto __p675 = this->b_h; auto __p676 = 28; return (f::__ci(), new f(__p673, __p674, __p675, __p676)); }()));
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p677 = (q::__ci(), q::a_i_String(39)); auto __p678 = (-1); auto __p679 = this->b_h; auto __p680 = 29; return (f::__ci(), new f(__p677, __p678, __p679, __p680)); }()));
         this->b_h->a_i_v(m::o_i);
         break;
      }
      case 28:
      {
         this->b_h->d_i_v(37);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->a_ii_v(5, 256);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(11, jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(m::v_i))) + jwint(4)));
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::v_i)));
         this->b_h->b_ii_v(4, 64);
         this->b_h->b_ii_v(3, 32);
         this->b_h->b_ii_v(2, 0);
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(87)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(50)), 0, 37, false);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(46)), 0, 25, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p681 = (q::__ci(), q::a_i_String(3)); auto __p682 = (-1); auto __p683 = this->b_h; auto __p684 = (-1); return (f::__ci(), new f(__p681, __p682, __p683, __p684)); }()));
         break;
      }
      case 29:
      {
         this->b_h->d_i_v(37);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         (m::A_i = 18);
         this->b_h->a_ii_v(5, 256);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(11, jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(m::v_i))) + jwint(4)));
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::v_i)));
         this->b_h->b_ii_v(4, 64);
         this->b_h->b_ii_v(3, 32);
         this->b_h->b_ii_v(2, 0);
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(89)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(50)), 0, 5, false);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(46)), 0, 25, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p685 = (q::__ci(), q::a_i_String(3)); auto __p686 = (-1); auto __p687 = this->b_h; auto __p688 = (-1); return (f::__ci(), new f(__p685, __p686, __p687, __p688)); }()));
         break;
      }
      case 30:
      {
         this->b_h->d_i_v(37);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         (m::A_i = 17);
         this->b_h->a_ii_v(5, 256);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(11, jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(m::v_i))) + jwint(4)));
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::v_i)));
         this->b_h->b_ii_v(4, 64);
         this->b_h->b_ii_v(3, 32);
         this->b_h->b_ii_v(2, 0);
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(82)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(50)), 0, 5, false);
         this->b_h->a_iStringiiz_v(1, (q::__ci(), q::a_i_String(46)), 0, 25, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p689 = (q::__ci(), q::a_i_String(3)); auto __p690 = (-1); auto __p691 = this->b_h; auto __p692 = (-1); return (f::__ci(), new f(__p689, __p690, __p691, __p692)); }()));
         break;
      }
      case 31:
      {
         this->b_h->d_i_v(36);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->b_ii_v(6, m::r_i);
         this->b_h->b_ii_v(7, m::s_i);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::t_i)));
         this->b_h->b_ii_v(11, jwrap32(jwint(([&]() { auto __l693 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); auto __r694 = (jshl(int32_t(m::u_i),1)); return jwrap32(jwint(__l693) - jwint(__r694)); }())) + jwint(4)));
         this->b_h->b_ii_v(9, jwrap32(jwint(([&]() { auto __l697 = (jshr(int32_t(([&]() { auto __l695 = (o::__ci(),o::b_i); auto __r696 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); return jwrap32(jwint(__l695) - jwint(__r696)); }())),1)); auto __r698 = m::u_i; return jwrap32(jwint(__l697) + jwint(__r698)); }())) - jwint(2)));
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(88)), (-1), 1);
         if (this->o_z) {
            this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(47)), 0, 33, true);
         } else {
            if (this->n_z) {
               this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(47)), 0, 32, true);
            } else {
               this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(47)), 0, 18, true);
            }
         }
         ([&]() -> decltype(auto) { auto& __a699 = ((L_var6 = newArr<JString>(1)))[0]; auto __v700 = jcat(JS(u""),m::p_i); return (__a699 = __v700); }());
         L_var10 = ([&]() -> decltype(auto) { auto __p701 = (q::__ci(), q::a_iAString_String(43, L_var6)); auto __p702 = (-1); auto __p703 = this->b_h; auto __p704 = (-1); return (f::__ci(), new f(__p701, __p702, __p703, __p704)); }());
         this->b_h->a_f_v(L_var10);
         (L_var6[0] = jcat(jcat(m::g_i,JS(u"/")),m::G_i));
         (L_var10 = (f::__ci(), new f(L_var6[0], 102, this->b_h, (-1))));
         if (m::e_z) {
            L_var10->a_ii_v(2, 16);
            L_var10->a_Stringi_v(L_var6[0], 102);
         }
         this->b_h->a_f_v(L_var10);
         ([&]() -> decltype(auto) { auto& __a705 = L_var6[0]; auto __v706 = m::b_i_String(jdiv(int32_t(m::a_i),int32_t(1000))); return (__a705 = __v706); }());
         (L_var10 = (f::__ci(), new f(L_var6[0], 103, this->b_h, (-1))));
         if (m::e_z) {
            L_var10->a_ii_v(2, 16);
            L_var10->a_Stringi_v(L_var6[0], 103);
         }
         this->b_h->a_f_v(L_var10);
         if (this->q_z) {
            ((L_var10 = ([&]() -> decltype(auto) { auto __p707 = (q::__ci(), q::a_i_String(41)); auto __p708 = (-1); auto __p709 = this->b_h; auto __p710 = (-1); return (f::__ci(), new f(__p707, __p708, __p709, __p710)); }())))->a_ii_v(1, 8);
            L_var10->a_Stringi_v((q::__ci(), q::a_i_String(41)), (-1));
            this->b_h->a_f_v(L_var10);
         }
         if (((m::a_i_z(13) && (!this->n_z)) && (!m::c_i_z(m::f_i)))) {
            bool L_var7 = false;
            if ((this->J_i > (-1))) {
               int32_t L_var14 = ((int32_t)(m::c_As[this->J_i]));
               (L_var7 = true);
               f* L_var3 = ([&]() -> decltype(auto) { auto __p711 = (q::__ci(), q::a_i_String(8)); auto __p712 = L_var14; auto __p713 = this->b_h; auto __p714 = (-1); return (f::__ci(), new f(__p711, __p712, __p713, __p714)); }());
               if (m::e_z) {
                  L_var3->a_ii_v(2, 0);
               } else {
                  L_var3->a_ii_v(2, 16);
               }
               L_var3->a_ii_v(3, 64);
               L_var3->a_ii_v(1, 8);
               ([&]() -> decltype(auto) { auto __p715 = (q::__ci(), q::a_i_String(8)); auto __p716 = L_var14; return L_var3->a_Stringi_v(__p715, __p716); }());
               this->b_h->a_f_v(L_var3);
            }
            if ((this->K_i > (-1))) {
               int32_t L_var15 = ((int32_t)(m::c_As[this->K_i]));
               (L_var7 = true);
               f* L_var19 = ([&]() -> decltype(auto) { auto __p717 = (q::__ci(), q::a_i_String(7)); auto __p718 = L_var15; auto __p719 = this->b_h; auto __p720 = (-1); return (f::__ci(), new f(__p717, __p718, __p719, __p720)); }());
               if (m::e_z) {
                  L_var19->a_ii_v(2, 0);
               } else {
                  L_var19->a_ii_v(2, 16);
               }
               L_var19->a_ii_v(3, 64);
               L_var19->a_ii_v(1, 8);
               ([&]() -> decltype(auto) { auto __p721 = (q::__ci(), q::a_i_String(7)); auto __p722 = L_var15; return L_var19->a_Stringi_v(__p721, __p722); }());
               this->b_h->a_f_v(L_var19);
            }
            if ((!L_var7)) {
               ((L_var10 = ([&]() -> decltype(auto) { auto __p723 = (q::__ci(), q::a_i_String(42)); auto __p724 = (-1); auto __p725 = this->b_h; auto __p726 = (-1); return (f::__ci(), new f(__p723, __p724, __p725, __p726)); }())))->a_ii_v(1, 8);
               L_var10->a_Stringi_v((q::__ci(), q::a_i_String(42)), (-1));
               this->b_h->a_f_v(L_var10);
            }
         }
         (this->n_z = false);
         (this->o_z = false);
         (this->J_i = (-1));
         (this->K_i = (-1));
         (this->q_z = false);
         m::a_hz_v(this->b_h, false);
         break;
      }
      case 32:
      {
         this->b_h->d_i_v(36);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->b_ii_v(6, m::r_i);
         this->b_h->b_ii_v(7, m::s_i);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::t_i)));
         this->b_h->b_ii_v(11, jwrap32(jwint(([&]() { auto __l727 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); auto __r728 = (jshl(int32_t(m::u_i),1)); return jwrap32(jwint(__l727) - jwint(__r728)); }())) + jwint(4)));
         this->b_h->b_ii_v(9, jwrap32(jwint(([&]() { auto __l731 = (jshr(int32_t(([&]() { auto __l729 = (o::__ci(),o::b_i); auto __r730 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); return jwrap32(jwint(__l729) - jwint(__r730)); }())),1)); auto __r732 = m::u_i; return jwrap32(jwint(__l731) + jwint(__r732)); }())) - jwint(2)));
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(83)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(47)), 0, 18, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p733 = (q::__ci(), q::a_i_String(5)); auto __p734 = (-1); auto __p735 = this->b_h; auto __p736 = (-1); return (f::__ci(), new f(__p733, __p734, __p735, __p736)); }()));
         break;
      }
      case 33:
      {
         this->b_h->d_i_v(36);
         this->b_h->a_ii_v(9, (-3));
         this->b_h->b_ii_v(13, (-2));
         this->b_h->b_ii_v(6, m::r_i);
         this->b_h->b_ii_v(7, m::s_i);
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::t_i)));
         this->b_h->b_ii_v(11, jwrap32(jwint(([&]() { auto __l737 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); auto __r738 = (jshl(int32_t(m::u_i),1)); return jwrap32(jwint(__l737) - jwint(__r738)); }())) + jwint(4)));
         this->b_h->b_ii_v(9, jwrap32(jwint(([&]() { auto __l741 = (jshr(int32_t(([&]() { auto __l739 = (o::__ci(),o::b_i); auto __r740 = jmath_min<int32_t>((o::__ci(),o::b_i), 240); return jwrap32(jwint(__l739) - jwint(__r740)); }())),1)); auto __r742 = m::u_i; return jwrap32(jwint(__l741) + jwint(__r742)); }())) - jwint(2)));
         this->b_h->a_Stringii_v((q::__ci(), q::a_i_String(84)), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(47)), 0, 18, true);
         this->b_h->a_f_v(([&]() -> decltype(auto) { auto __p743 = (q::__ci(), q::a_i_String(6)); auto __p744 = (-1); auto __p745 = this->b_h; auto __p746 = (-1); return (f::__ci(), new f(__p743, __p744, __p745, __p746)); }()));
         break;
      }
      case 34:
      {
         this->b_h->a_ii_v(9, (-1));
         this->b_h->b_ii_v(13, (-1));
         this->b_h->b_ii_v(15, 2);
         this->b_h->b_ii_v(16, 2);
         this->b_h->b_ii_v(11, jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(m::v_i))) + jwint(4)));
         this->b_h->b_ii_v(12, jwrap32(jwint((o::__ci(),o::c_i)) - jwint(m::v_i)));
         this->b_h->b_ii_v(4, 64);
         this->b_h->b_ii_v(3, 32);
         this->b_h->b_ii_v(2, 0);
         this->b_h->a_Stringii_v(JS(u""), (-1), 1);
         this->b_h->a_iStringiiz_v(0, (q::__ci(), q::a_i_String(47)), 0, 35, true);
         if (m::i_z) {
            this->b_h->a_f_v((f::__ci(), new f(m::a_String, (-1), this->b_h, (-1))));
            (m::i_z = false);
         } else {
            JString L_var2{};
            if ((m::a_AString != nullptr)) {
               (L_var2 = (q::__ci(), q::a_iAString_String(m::n_Ai[0], m::a_AString)));
               (m::a_AString = nullptr);
            } else {
               (L_var2 = (q::__ci(), q::a_i_String(m::n_Ai[0])));
            }
            if (L_var2.endsWith(JS(u"\n\n"))) {
               (L_var2 = L_var2.substring(0, jwrap32(jwint(L_var2.length()) - jwint(2))));
            } else {
               if (L_var2.startsWith(JS(u"\n\n"))) {
                  (L_var2 = L_var2.substring(2, L_var2.length()));
               }
            }
            (m::a_String = L_var2);
            this->b_h->a_f_v((f::__ci(), new f(L_var2, (-1), this->b_h, (-1))));
         }
      }
      }
   }
   (this->a_h = this->b_h);
   this->b_h->b__v();
   (o::__ci(), o::d_i_v(2));
   (o::__ci(), o::c__v());
}
void m::b__v() {
   (this->a_h = nullptr);
   (o::__ci(), o::b__v());
   (o::__ci(), o::a_iStringi_v(1, JS(u""), 1));
   (o::__ci(), o::d_i_v(2));
   (o::__ci(), o::c__v());
}
void m::a_hz_v(h* L_var0, bool L_var1) {
   bool L_var2 = false;
   if ((m::k_i != 14)) {
      if ((m::l_i < m::k_i)) {
         (L_var2 = true);
      }
      (m::l_i = (m::k_i++));
      if (((m::m_i == 0) || L_var2)) {
         (m::m_i = 650);
      }
      (m::n_i = 0);
      if (L_var1) {
         m::a_h_v(L_var0);
      }
   }
}
void m::a_h_v(h* L_var0) {
   if (m::b_i_z(m::k_i)) {
      L_var0->a_iStringi_v(0, (q::__ci(), q::a_i_String(49)), 0);
   } else {
      L_var0->a_iStringi_v(0, nullptr, 0);
   }
}
bool m::a_hiiiii_z(h* L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5) {
   (o::__ci(), o::b_z_v(true));
   JGraphics L_var6 = (o::__ci(), o::a__Graphics());
   int32_t L_var7 = ([&]() { auto __l747 = (o::__ci(),o::a_i); auto __r748 = (o::__ci(), o::a__i()); return jwrap32(jwint(__l747) * jwint(__r748)); }());
   JDirectGraphics L_var8 = nullptr;
   (L_var8 = JDirectUtils::getDirectGraphics(L_var6));
   if ((((((((L_var0->a_i == 34) || (L_var0->a_i == 25)) || (L_var0->a_i == 28)) || (L_var0->a_i == 29)) || (L_var0->a_i == 30))) && (L_var1 == 1))) {
      Arr<int32_t> L_var21 = (p::__ci(),p::a_Ai);
      Arr<int32_t> L_var43 = (p::__ci(),p::b_Ai);
      (L_var21[0] = L_var2);
      (L_var43[0] = L_var3);
      (L_var21[1] = jwrap32(jwint(L_var2) + jwint(L_var4)));
      (L_var43[1] = L_var3);
      (L_var21[2] = jwrap32(jwint(L_var2) + jwint(L_var4)));
      (L_var43[2] = jwrap32(jwint(L_var3) + jwint(L_var5)));
      (L_var21[3] = L_var2);
      (L_var43[3] = jwrap32(jwint(L_var3) + jwint(L_var5)));
      L_var8->fillPolygon(L_var21, 0, L_var43, 0, 4, 1426063360);
      (o::__ci(), o::a_iii_v(L_var2, L_var3, 311));
      (o::__ci(), o::a_iii_v(jwrap32(jwint(L_var2) + jwint(L_var4)), L_var3, 312));
      (o::__ci(), o::a_iii_v(L_var2, jwrap32(jwint(L_var3) + jwint(L_var5)), 309));
      (o::__ci(), o::a_iii_v(jwrap32(jwint(L_var2) + jwint(L_var4)), jwrap32(jwint(L_var3) + jwint(L_var5)), 310));
      m::a_DirectGraphics_v(L_var8);
      return false;
   } else {
      if ((L_var0->a_i != 18)) {
         if ((((((((L_var0->a_i != 25) && (L_var0->a_i != 28)) && (L_var0->a_i != 29)) && (L_var0->a_i != 30)) && (L_var0->a_i != 15)) && (L_var0->a_i != 34)) && (L_var1 == 1))) {
            m::a_Graphics_v(L_var6);
            (L_var1 = jshr(int32_t((o::__ci(),o::b_i)),1));
            int32_t L_var42 = jshr(int32_t((o::__ci(),o::c_i)),1);
            if ((L_var0->a_i == 17)) {
               int32_t L_var15{};
               (L_var2 = jshr(int32_t(((L_var15 = (o::__ci(), o::b_ii_i(332, 0))))),16));
               int32_t L_var25 = ((int32_t)(((int16_t)(L_var15))));
               int32_t L_var16{};
               (L_var4 = jshr(int32_t(((L_var16 = (o::__ci(), o::b_ii_i(332, 1))))),16));
               int32_t L_var17 = ((int32_t)(((int16_t)(L_var16))));
               (L_var5 = jwrap32(jwint(L_var1) - jwint(117)));
               (L_var7 = jwrap32(jwint(L_var42) - jwint(157)));
               int32_t L_var47{};
               (L_var47 = ([&]() { auto __l749 = ((L_var47 = jwrap32(jwint(L_var1) + jwint(L_var4)))); auto __r750 = L_var5; return jwrap32(jwint(__l749) - jwint(__r750)); }()));
               L_var6->setColor(6570800);
               L_var6->fillRect(jwrap32(jwint(L_var1) + jwint(L_var2)), jwrap32(jwint(L_var42) + jwint(L_var25)), jwrap32(jwint(L_var4) - jwint(L_var2)), jwrap32(jwint(L_var17) - jwint(L_var25)));
               (o::__ci(), o::a_iii_v(L_var1, L_var42, 332));
               L_var6->setColor(5580559);
               L_var6->drawRect(jwrap32(jwint(L_var5) + jwint(2)), jwrap32(jwint(L_var7) + jwint(2)), jwrap32(jwint(L_var47) - jwint(4)), 296);
               L_var6->drawRect(jwrap32(jwint(L_var5) + jwint(3)), jwrap32(jwint(L_var7) + jwint(3)), jwrap32(jwint(L_var47) - jwint(6)), 294);
               L_var6->setColor(3610889);
               L_var6->drawRect(L_var5, L_var7, L_var47, 300);
               L_var6->drawRect(jwrap32(jwint(L_var5) + jwint(1)), jwrap32(jwint(L_var7) + jwint(1)), jwrap32(jwint(L_var47) - jwint(2)), 298);
               (o::__ci(), o::a_iiiii_v(jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var1) + jwint(L_var47))) - jwint(117))) + jwint(2)), jwrap32(jwint(jwrap32(jwint(L_var42) - jwint(157))) - jwint(2)), 12, 24, 6));
               (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var1) + jwint(L_var47))) - jwint(117))) + jwint(2)), jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var42) + jwint(300))) - jwint(157))) + jwint(2)), 12, 40));
               (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(L_var1) - jwint(117))) - jwint(5)), jwrap32(jwint(L_var42) - jwint(75)), 15, 6));
               (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(L_var1) - jwint(117))) - jwint(5)), jwrap32(jwint(L_var42) + jwint(75)), 15, 6));
            } else {
               m::a_iiGraphics_v(L_var1, L_var42, L_var6);
            }
            m::a_DirectGraphics_v(L_var8);
            return false;
         } else {
            if ((L_var1 == 1)) {
               m::a_DirectGraphics_v(L_var8);
            }
            if ((L_var1 == 4)) {
               return false;
            } else {
               if ((L_var1 == 2)) {
                  return false;
               } else {
                  if ((L_var1 == 9)) {
                     return false;
                  } else {
                     if (((((((L_var0->a_i != 25) && (L_var0->a_i != 28)) && (L_var0->a_i != 29)) && (L_var0->a_i != 30)) && (L_var0->a_i != 34)) && (L_var1 == 10))) {
                        L_var6->setClip(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
                        (L_var1 = jdiv(int32_t(jwrap32(jwint(m::b_As[((int32_t)((jrem(int64_t((jshr(int64_t(JSystem::currentTimeMillis()),1))),int64_t((int64_t)360LL)))))]) * jwint(5))),int32_t(360)));
                        (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var2) - jwint(5))) - jwint(4))) + jwint(L_var1)), jwrap32(jwint(L_var3) + jwint((jshr(int32_t(L_var5),1)))), 2, 10));
                        (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var2) + jwint(L_var4))) + jwint(5))) + jwint(4))) - jwint(L_var1)), jwrap32(jwint(L_var3) + jwint((jshr(int32_t(L_var5),1)))), 326, 6));
                        return false;
                     } else {
                        return true;
                     }
                  }
               }
            }
         }
      } else {
         if ((L_var1 == 1)) {
            m::a_Graphics_v(L_var6);
            (L_var1 = jshr(int32_t((o::__ci(),o::b_i)),1));
            int32_t L_var9 = jshr(int32_t((o::__ci(),o::c_i)),1);
            (L_var2 = ([&]() { auto __l751 = ((int16_t)((o::__ci(), o::b_ii_i(331, 2)))); auto __r752 = L_var9; return jwrap32(jwint(__l751) + jwint(__r752)); }()));
            (L_var3 = ([&]() { auto __l753 = ((int16_t)((o::__ci(), o::b_ii_i(331, 3)))); auto __r754 = L_var9; return jwrap32(jwint(__l753) + jwint(__r754)); }()));
            m::a_iiGraphics_v(L_var1, L_var9, L_var6);
            if ((m::k_i != 0)) {
               (o::__ci(), o::a_iiii_v(3, L_var9, 326, 6));
            }
            if ((m::k_i != 14)) {
               (o::__ci(), o::a_iiii_v(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(3)), L_var9, 2, 10));
            }
            (L_var4 = 0);
            int32_t L_var12 = 0;
            if ((m::m_i < m::n_i)) {
               if (([&]() { auto __l755 = ((m::m_i += L_var7)); auto __r756 = m::n_i; return (__l755 > __r756); }())) {
                  (m::m_i = m::n_i);
               }
               (L_var4 = m::k_i);
               (L_var12 = m::l_i);
            } else {
               if ((m::m_i > m::n_i)) {
                  if (([&]() { auto __l757 = ((m::m_i -= L_var7)); auto __r758 = m::n_i; return (__l757 < __r758); }())) {
                     (m::m_i = m::n_i);
                  }
                  (L_var4 = m::l_i);
                  (L_var12 = m::k_i);
               }
            }
            if (((m::m_i > 400) && (m::m_i < 650))) {
               bool L_var32 = false;
               int32_t L_var14 = jdiv(int32_t((jshl(int32_t(jwrap32(jwint(m::m_i) - jwint(400))),1))),int32_t(250));
               m::a_iiiii_v(L_var1, L_var9, L_var4, L_var2, L_var3);
               (o::__ci(), o::b_iiii_v(L_var1, L_var9, 442, L_var14));
            } else {
               if (((m::m_i <= 400) && (m::m_i > 0))) {
                  int32_t L_var28 = 0;
                  (L_var28 = 0);
                  int32_t L_var35 = 0;
                  int32_t L_var10 = 0;
                  (L_var10 = 0);
                  (L_var28 = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var1) - jwint(119))) - jwint(239))) + jwint(22)));
                  (L_var35 = jwrap32(jwint(jwrap32(jwint(L_var1) + jwint(120))) + jwint((-30))));
                  (L_var10 = jwrap32(jwint(jwrap32(jwint(L_var1) - jwint(119))) + jwint(22)));
                  int32_t L_var37{};
                  int32_t L_var38 = ([&]() { auto __l759 = ((L_var37 = jwrap32(jwint(L_var35) - jwint(25)))); auto __r760 = L_var28; return jwrap32(jwint(__l759) - jwint(__r760)); }());
                  int32_t L_var49 = jwrap32(jwint(L_var35) - jwint(L_var10));
                  (L_var28 = jwrap32(jwint(jdiv(int32_t(jwrap32(jwint(m::m_i) * jwint(L_var38))),int32_t(400))) + jwint(L_var28)));
                  (L_var35 = jwrap32(jwint(jdiv(int32_t(jwrap32(jwint(m::m_i) * jwint(L_var49))),int32_t(400))) + jwint(L_var10)));
                  (L_var10 = jwrap32(jwint(jwrap32(jwint(L_var9) - jwint(158))) + jwint((-3))));
                  L_var6->setClip(0, 0, jwrap32(jwint(L_var28) + jwint(3)), (o::__ci(),o::c_i));
                  m::a_iiiii_v(L_var1, L_var9, L_var4, L_var2, L_var3);
                  L_var6->setClip(jwrap32(jwint(L_var35) - jwint(2)), 0, jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(L_var35))) + jwint(2)), (o::__ci(),o::c_i));
                  m::a_iiiii_v(L_var1, L_var9, L_var12, L_var2, L_var3);
                  L_var6->setClip(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
                  (o::__ci(), o::a_iii_v(L_var28, L_var10, 377));
                  L_var6->setColor(15394508);
                  int32_t L_var13 = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var35) - jwint(L_var28))) - jwint(12))) - jwint(13));
                  L_var6->fillRect(jwrap32(jwint(L_var28) + jwint(12)), L_var10, L_var13, 295);
                  L_var6->setColor(0);
                  L_var6->fillRect(jwrap32(jwint(L_var28) + jwint(12)), L_var10, L_var13, 1);
                  L_var6->fillRect(jwrap32(jwint(L_var28) + jwint(12)), jwrap32(jwint(jwrap32(jwint(jwrap32(jwint(L_var10) + jwint(307))) - jwint(1))) + jwint((-12))), L_var13, 1);
                  (o::__ci(), o::a_iii_v(jwrap32(jwint(jwrap32(jwint(L_var28) + jwint(12))) + jwint(L_var13)), L_var10, 378));
                  (o::__ci(), o::a_iii_v(L_var1, L_var9, 376));
               } else {
                  m::a_iiiii_v(L_var1, L_var9, m::k_i, L_var2, L_var3);
               }
            }
            (o::__ci(), o::a_ii_v((-3), 3));
            (o::__ci(), o::b_ii_v(0, 16742400));
            (o::__ci(), o::b_ii_v(1, 0));
            (o::__ci(), o::a_iii_v(9, 9, 102));
            JString L_var33{};
            ([&]() -> decltype(auto) { auto __p761 = (L_var33 = jcat(jcat(m::c__i(),JS(u"/")),450)); auto __p762 = 0; auto __p763 = L_var33.length(); auto __p764 = 41; auto __p765 = 10; auto __p766 = 20; return (o::__ci(), o::a_Stringiiiii_v(__p761, __p762, __p763, __p764, __p765, __p766)); }());
            m::a_DirectGraphics_v(L_var8);
         }
         return false;
      }
   }
}
void m::a_Graphics_v(JGraphics L_var0) {
   L_var0->setColor(4135425);
   L_var0->fillRect(0, 0, jshr(int32_t((o::__ci(),o::b_i)),1), (o::__ci(),o::c_i));
   L_var0->setColor(6170113);
   L_var0->fillRect(jshr(int32_t((o::__ci(),o::b_i)),1), 0, jshr(int32_t((o::__ci(),o::b_i)),1), (o::__ci(),o::c_i));
   (o::__ci(), o::a_iii_v(0, 0, 4));
   (o::__ci(), o::a_iii_v(0, 0, 74));
   (o::__ci(), o::a_iii_v(0, 0, 75));
   (o::__ci(), o::a_iii_v(0, (o::__ci(),o::c_i), 3));
}
int32_t m::d_i_i(int32_t L_var0) {
   int32_t L_var1 = (-1);
   int32_t L_var2 = jshl(int32_t(L_var0),2);
   if ((m::f_As[L_var2] >= m::d_As[jwrap32(jwint(L_var0) * jwint(3))])) {
      (L_var1 = 2);
   } else {
      if ((m::f_As[L_var2] >= m::d_As[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(3))) + jwint(1))])) {
         (L_var1 = 1);
      } else {
         if ((m::f_As[L_var2] >= m::d_As[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(3))) + jwint(2))])) {
            (L_var1 = 0);
         }
      }
   }
   return L_var1;
}
int32_t m::e_i_i(int32_t L_var0) {
   int32_t L_var1 = (-1);
   int32_t L_var2 = jshl(int32_t(L_var0),2);
   if ((m::f_As[jwrap32(jwint(L_var2) + jwint(1))] <= m::e_As[jwrap32(jwint(L_var0) * jwint(3))])) {
      (L_var1 = 2);
   } else {
      if ((m::f_As[jwrap32(jwint(L_var2) + jwint(1))] <= m::e_As[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(3))) + jwint(1))])) {
         (L_var1 = 1);
      } else {
         if ((m::f_As[jwrap32(jwint(L_var2) + jwint(1))] <= m::e_As[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(3))) + jwint(2))])) {
            (L_var1 = 0);
         }
      }
   }
   return L_var1;
}
void m::a_iiiii_v(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4) {
   int32_t L_var5{};
   if ((((L_var5 = m::b_i_i(L_var2))) == 0)) {
      (o::__ci(), o::a_iii_v(L_var0, L_var1, 8));
   } else {
      if ((L_var5 == 2)) {
         (o::__ci(), o::a_iii_v(L_var0, L_var1, 380));
      }
   }
   (o::__ci(), o::a_iii_v(L_var0, L_var1, ((int32_t)(m::g_As[L_var2]))));
   Arr<JString> L_var24 = newArr<JString>(1);
   (o::__ci(), o::a_ii_v((-3), 1));
   (o::__ci(), o::b_ii_v(0, 0));
   if ((!m::b_i_z(L_var2))) {
      (o::__ci(), o::a_iii_v(L_var0, L_var1, 149));
      if (m::c_i_z(L_var2)) {
         int32_t L_var6 = 0;
         for (int32_t L_var7 = 0; (L_var7 < m::c_Ai.length()); (L_var7 += 2)) {
            {
               if ((L_var2 == m::c_Ai[L_var7])) {
                  (L_var6 = m::c_Ai[jwrap32(jwint(L_var7) + jwint(1))]);
               }
            }
         }
         (L_var24[0] = jcat(JS(u""),L_var6));
         JString L_var13 = (q::__ci(), q::a_iAString_String(0, L_var24));
         int32_t L_var9 = jwrap32(jwint(jwrap32(jwint(([&]() -> decltype(auto) { auto __p767 = (-3); auto __p768 = L_var13; auto __p769 = 0; auto __p770 = L_var13.length(); return (o::__ci(), o::a_iStringii_i(__p767, __p768, __p769, __p770)); }())) + jwint(23))) + jwint(5));
         int32_t L_var8{};
         (L_var6 = ([&]() { auto __l771 = ((L_var8 = jwrap32(jwint((jshr(int32_t((o::__ci(),o::b_i)),1))) - jwint((jshr(int32_t(L_var9),1)))))); auto __r772 = L_var9; return jwrap32(jwint(__l771) + jwint(__r772)); }()));
         if (m::e_z) {
            (o::__ci(), o::a_iiii_v(L_var6, L_var4, 102, 24));
            ([&]() -> decltype(auto) { auto __p773 = L_var13; auto __p774 = 0; auto __p775 = L_var13.length(); auto __p776 = L_var8; auto __p777 = L_var4; auto __p778 = 20; return (o::__ci(), o::a_Stringiiiii_v(__p773, __p774, __p775, __p776, __p777, __p778)); }());
         } else {
            (o::__ci(), o::a_iiii_v(L_var8, L_var4, 102, 20));
            ([&]() -> decltype(auto) { auto __p779 = L_var13; auto __p780 = 0; auto __p781 = L_var13.length(); auto __p782 = jwrap32(jwint(jwrap32(jwint(L_var8) + jwint(23))) + jwint(5)); auto __p783 = L_var4; auto __p784 = 20; return (o::__ci(), o::a_Stringiiiii_v(__p779, __p780, __p781, __p782, __p783, __p784)); }());
         }
      }
   } else {
      int32_t L_var26 = jwrap32(jwint((o::__ci(), o::a_i_i((-3)))) + jwint(1));
      int32_t L_var27 = jwrap32(jwint(jwrap32(jwint((o::__ci(), o::a_i_i((-3)))) + jwint(23))) + jwint(3));
      (L_var24[0] = JS(u"9999"));
      JString L_var14 = (q::__ci(), q::a_iAString_String(43, L_var24));
      int32_t L_var28 = ([&]() -> decltype(auto) { auto __p785 = (-3); auto __p786 = L_var14; auto __p787 = 0; auto __p788 = L_var14.length(); return (o::__ci(), o::a_iStringii_i(__p785, __p786, __p787, __p788)); }());
      ([&]() -> decltype(auto) { auto& __a789 = L_var24[0]; auto __v790 = JInteger::toString(0); return (__a789 = __v790); }());
      int32_t L_var30 = jshl(int32_t(L_var2),2);
      if ((m::f_As[jwrap32(jwint(L_var30) + jwint(2))] > 0)) {
         (L_var24[0] = jcat(JS(u""),(int32_t)(m::f_As[jwrap32(jwint(L_var30) + jwint(2))])));
      }
      (L_var28 = jwrap32(jwint(jwrap32(jwint((jshr(int32_t((o::__ci(),o::b_i)),1))) - jwint((jshr(int32_t(L_var28),1))))) - jwint(6)));
      JString L_var15 = JS(u"00/00");
      int32_t L_var10 = jwrap32(jwint(jwrap32(jwint(([&]() -> decltype(auto) { auto __p791 = (-3); auto __p792 = L_var15; auto __p793 = 0; auto __p794 = L_var15.length(); return (o::__ci(), o::a_iStringii_i(__p791, __p792, __p793, __p794)); }())) + jwint(23))) + jwint(11));
      JString L_var16 = (q::__ci(), q::a_iAString_String(43, L_var24));
      if (m::e_z) {
         ([&]() -> decltype(auto) { auto __p795 = L_var16; auto __p796 = 0; auto __p797 = L_var16.length(); auto __p798 = jwrap32(jwint(jwrap32(jwint(L_var28) + jwint(L_var10))) + jwint(23)); auto __p799 = L_var4; auto __p800 = 24; return (o::__ci(), o::a_Stringiiiii_v(__p795, __p796, __p797, __p798, __p799, __p800)); }());
      } else {
         ([&]() -> decltype(auto) { auto __p801 = L_var16; auto __p802 = 0; auto __p803 = L_var16.length(); auto __p804 = L_var28; auto __p805 = L_var4; auto __p806 = 20; return (o::__ci(), o::a_Stringiiiii_v(__p801, __p802, __p803, __p804, __p805, __p806)); }());
      }
      if ((!m::c_i_z(L_var2))) {
         (L_var24[0] = jcat(jcat(jcat(JS(u""),(int32_t)(m::f_As[L_var30])),JS(u"/")),30));
         JString L_var17 = L_var24[0];
         if (m::e_z) {
            (o::__ci(), o::a_iiii_v(jwrap32(jwint(L_var28) + jwint(L_var10)), jwrap32(jwint(L_var4) + jwint(L_var26)), 102, 20));
            ([&]() -> decltype(auto) { auto __p807 = L_var17; auto __p808 = 0; auto __p809 = L_var17.length(); auto __p810 = jwrap32(jwint(jwrap32(jwint(L_var28) - jwint(11))) + jwint(L_var10)); auto __p811 = jwrap32(jwint(jwrap32(jwint(L_var4) + jwint(L_var26))) + jwint(11)); auto __p812 = 10; return (o::__ci(), o::a_Stringiiiii_v(__p807, __p808, __p809, __p810, __p811, __p812)); }());
         } else {
            (o::__ci(), o::a_iiii_v(L_var28, jwrap32(jwint(L_var4) + jwint(L_var26)), 102, 20));
            ([&]() -> decltype(auto) { auto __p813 = L_var17; auto __p814 = 0; auto __p815 = L_var17.length(); auto __p816 = jwrap32(jwint(jwrap32(jwint(L_var28) + jwint(23))) + jwint(11)); auto __p817 = jwrap32(jwint(jwrap32(jwint(L_var4) + jwint(L_var26))) + jwint(11)); auto __p818 = 6; return (o::__ci(), o::a_Stringiiiii_v(__p813, __p814, __p815, __p816, __p817, __p818)); }());
         }
      }
      if ((m::a_i_z(13) && (!m::c_i_z(L_var2)))) {
         int32_t L_var11{};
         if ((((L_var11 = m::d_i_i(L_var2))) > (-1))) {
            (L_var11 = ((int32_t)(m::c_As[L_var11])));
         }
         int32_t L_var12{};
         if ((((L_var12 = m::e_i_i(L_var2))) > (-1))) {
            (L_var12 = ((int32_t)(m::c_As[L_var12])));
         }
         ([&]() -> decltype(auto) { auto& __a819 = L_var24[0]; auto __v820 = m::b_i_String(((int32_t)(m::f_As[jwrap32(jwint(L_var30) + jwint(1))]))); return (__a819 = __v820); }());
         JString L_var18 = L_var24[0];
         if (m::e_z) {
            (o::__ci(), o::a_iiii_v(jwrap32(jwint(L_var28) + jwint(L_var10)), jwrap32(jwint(L_var4) + jwint(L_var27)), 103, 20));
            ([&]() -> decltype(auto) { auto __p821 = L_var18; auto __p822 = 0; auto __p823 = L_var18.length(); auto __p824 = jwrap32(jwint(jwrap32(jwint(L_var28) - jwint(11))) + jwint(L_var10)); auto __p825 = jwrap32(jwint(jwrap32(jwint(L_var4) + jwint(L_var27))) + jwint(11)); auto __p826 = 10; return (o::__ci(), o::a_Stringiiiii_v(__p821, __p822, __p823, __p824, __p825, __p826)); }());
         } else {
            (o::__ci(), o::a_iiii_v(L_var28, jwrap32(jwint(L_var4) + jwint(L_var27)), 103, 20));
            ([&]() -> decltype(auto) { auto __p827 = L_var18; auto __p828 = 0; auto __p829 = L_var18.length(); auto __p830 = jwrap32(jwint(jwrap32(jwint(L_var28) + jwint(23))) + jwint(11)); auto __p831 = jwrap32(jwint(jwrap32(jwint(L_var4) + jwint(L_var27))) + jwint(11)); auto __p832 = 6; return (o::__ci(), o::a_Stringiiiii_v(__p827, __p828, __p829, __p830, __p831, __p832)); }());
         }
         JString L_var19 = JS(u"00:00");
         (L_var1 = jwrap32(jwint(jwrap32(jwint(([&]() -> decltype(auto) { auto __p833 = (-3); auto __p834 = L_var19; auto __p835 = 0; auto __p836 = L_var19.length(); return (o::__ci(), o::a_iStringii_i(__p833, __p834, __p835, __p836)); }())) + jwint(23))) + jwint(11)));
         if (m::e_z) {
            if ((L_var11 > (-1))) {
               (o::__ci(), o::a_iiii_v(L_var28, jwrap32(jwint(L_var4) + jwint(L_var26)), L_var11, 24));
            }
            if ((L_var12 > (-1))) {
               (o::__ci(), o::a_iiii_v(L_var28, jwrap32(jwint(L_var4) + jwint(L_var27)), L_var12, 12));
            }
         } else {
            if ((L_var11 > (-1))) {
               (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(L_var28) + jwint(L_var1))) + jwint(11)), jwrap32(jwint(L_var4) + jwint(L_var26)), L_var11, 20));
            }
            if ((L_var12 > (-1))) {
               (o::__ci(), o::a_iiii_v(jwrap32(jwint(jwrap32(jwint(L_var28) + jwint(L_var1))) + jwint(11)), jwrap32(jwint(L_var4) + jwint(L_var27)), L_var12, 20));
            }
         }
      }
   }
   (o::__ci(), o::a_ii_v((-2), 3));
   (o::__ci(), o::b_ii_v(0, 16742400));
   (o::__ci(), o::b_ii_v(1, 0));
   if (m::c_i_z(L_var2)) {
      ([&]() -> decltype(auto) { auto& __a837 = L_var24[0]; auto __v838 = m::a_i_String(L_var2); return (__a837 = __v838); }());
      JString L_var21{};
      ([&]() -> decltype(auto) { auto __p841 = (L_var21 = (q::__ci(), q::a_iAString_String(16, L_var24))); auto __p842 = 0; auto __p843 = L_var21.length(); auto __p844 = L_var0; auto __p845 = ([&]() { auto __l839 = L_var3; auto __r840 = (o::__ci(), o::a_i_i((o::__ci(), o::f__i()))); return jwrap32(jwint(__l839) - jwint(__r840)); }()); auto __p846 = 33; return (o::__ci(), o::a_Stringiiiii_v(__p841, __p842, __p843, __p844, __p845, __p846)); }());
   } else {
      ([&]() -> decltype(auto) { auto& __a847 = L_var24[0]; auto __v848 = m::a_i_String(L_var2); return (__a847 = __v848); }());
      JString L_var22{};
      ([&]() -> decltype(auto) { auto __p851 = (L_var22 = (q::__ci(), q::a_iAString_String(35, L_var24))); auto __p852 = 0; auto __p853 = L_var22.length(); auto __p854 = L_var0; auto __p855 = ([&]() { auto __l849 = L_var3; auto __r850 = (o::__ci(), o::a_i_i((o::__ci(), o::f__i()))); return jwrap32(jwint(__l849) - jwint(__r850)); }()); auto __p856 = 33; return (o::__ci(), o::a_Stringiiiii_v(__p851, __p852, __p853, __p854, __p855, __p856)); }());
   }
   JString L_var23{};
   ([&]() -> decltype(auto) { auto __p857 = (L_var23 = (q::__ci(), q::a_i_String(((int32_t)(m::h_As[L_var2]))))); auto __p858 = 0; auto __p859 = L_var23.length(); auto __p860 = L_var0; auto __p861 = L_var3; auto __p862 = 33; return (o::__ci(), o::a_Stringiiiii_v(__p857, __p858, __p859, __p860, __p861, __p862)); }());
}
JString m::a_i_String(int32_t L_var0) {
   int32_t L_var1 = 0;
   for (int32_t L_var2 = 0; ((L_var2 < m::c_Ai.length()) && (L_var0 >= m::c_Ai[L_var2])); (L_var2 += 2)) {
      {
         (L_var1++);
      }
   }
   return (m::c_i_z(L_var0) ? jcat(JS(u""),L_var1) : jcat(JS(u""),(jwrap32(jwint(jwrap32(jwint(L_var0) + jwint(1))) - jwint(L_var1)))));
}
void m::a_iiGraphics_v(int32_t L_var0, int32_t L_var1, JGraphics L_var2) {
   (o::__ci(), o::a_iii_v(L_var0, L_var1, 331));
   int32_t L_var3{};
   int32_t L_var4 = jshr(int32_t(((L_var3 = (o::__ci(), o::b_ii_i(331, 0))))),16);
   int32_t L_var5 = ((int32_t)(((int16_t)(L_var3))));
   int32_t L_var6 = jshr(int32_t(((L_var3 = (o::__ci(), o::b_ii_i(331, 1))))),16);
   int32_t L_var8 = ((int32_t)(((int16_t)(L_var3))));
   L_var2->setColor(16512995);
   L_var2->fillRect(jwrap32(jwint(L_var0) + jwint(L_var6)), jwrap32(jwint(L_var1) + jwint(L_var8)), jwrap32(jwint(L_var4) - jwint(L_var6)), jwrap32(jwint(L_var5) - jwint(L_var8)));
   L_var2->setColor(0);
   L_var2->fillRect(jwrap32(jwint(jwrap32(jwint(L_var0) + jwint(L_var6))) - jwint(2)), jwrap32(jwint(L_var1) + jwint(L_var8)), 4, jwrap32(jwint(L_var5) - jwint(L_var8)));
}
void m::a_i_v(int32_t L_var0) {
   if ((m::z_i < 5)) {
      (m::n_Ai[m::z_i] = L_var0);
      (m::z_i++);
   }
}
void m::c__v() {
   if (((!m::g_z) && (m::z_i > 0))) {
      this->g_i_v(34);
      (m::h_z = true);
      (m::g_z = true);
      for (int32_t L_var1 = 0; (L_var1 < 4); (L_var1++)) {
         {
            (m::n_Ai[L_var1] = m::n_Ai[jwrap32(jwint(L_var1) + jwint(1))]);
         }
      }
      (m::z_i--);
   }
}
void m::b_i_v(int32_t L_var1) {
   if ((this->a_h != nullptr)) {
      h* L_var4 = this->a_h;
      if ((L_var4->a_i == 18)) {
         if (m::f_z) {
            if ((m::a_Ab[m::a_b] == L_var1)) {
               if (([&]() { auto __l863 = (++m::a_b); auto __r864 = m::a_Ab.length(); return (__l863 == __r864); }())) {
                  for (int32_t L_var5 = 0; (L_var5 < 15); (L_var5++)) {
                     {
                        m::f_i_v(L_var5);
                     }
                  }
                  (m::a_b = ((int8_t)(0)));
                  m::a_h_v(L_var4);
                  m::d__v();
               }
            } else {
               if ((m::b_Ab[m::a_b] != L_var1)) {
                  (m::a_b = ((int8_t)(0)));
               } else {
                  if (([&]() { auto __l865 = (++m::a_b); auto __r866 = m::b_Ab.length(); return (__l865 == __r866); }())) {
                     for (int32_t L_var2 = 0; (L_var2 < 15); (L_var2++)) {
                        {
                           m::f_i_v(L_var2);
                           m::a_isss_v(L_var2, ((int16_t)(30)), ((int16_t)(1)), ((int16_t)(9999)));
                        }
                     }
                     (m::a_b = ((int8_t)(0)));
                     m::a_h_v(L_var4);
                     m::d__v();
                  }
               }
            }
         }
         {
            bool L_var3{};
            switch (L_var1) {
            case 3:
            {
               L_var3 = false;
               if ((m::k_i != 0)) {
                  if ((m::l_i > m::k_i)) {
                     (L_var3 = true);
                  }
                  (m::l_i = (m::k_i--));
                  if (((m::m_i == 650) || L_var3)) {
                     (m::m_i = 0);
                  }
                  (m::n_i = 650);
                  m::a_h_v(L_var4);
               }
               break;
            }
            case 4:
            {
               m::a_hz_v(L_var4, true);
            }
            }
         }
      }
      bool L_var10000 = false;
      this->a_h->c_i_v(L_var1);
   } else {
      if ((this->j_i == 2)) {
         this->e__v();
      } else {
         if (((this->j_i != 3) && (this->j_i == 4))) {
            if (m::f_z) {
               if (((m::a_Ab[m::a_b] == L_var1) && ((((g::__ci(),g::a_Ai)[1] == 0) || ((g::__ci(),g::a_Ai)[1] == 1))))) {
                  if (([&]() { auto __l867 = (++m::a_b); auto __r868 = m::a_Ab.length(); return (__l867 == __r868); }())) {
                     ((g::__ci(),g::a_Ai)[0] = 2);
                     (m::a_b = ((int8_t)(0)));
                     (m::g_i = 30);
                  }
               } else {
                  (m::a_b = ((int8_t)(0)));
               }
            }
            {
               switch (L_var1) {
               case 5:
               {
                  (m::b_z = true);
                  return;
               }
               case 20:
               {
                  if ((((g::__ci(),g::a_Ai)[1] == 0) && ((g::__ci(),g::a_Ai)[0] != 3))) {
                     m::a_c->f__v();
                  }
               }
               }
            }
         }
      }
   }
}
int32_t m::a_i_i(int32_t L_var1) {
   if ((this->a_h != nullptr)) {
      this->a_h->b__v();
      this->a_h->c__v();
   } else {
      if ((this->j_i == 2)) {
         return 0;
      }
      if ((this->j_i == 4)) {
         if (m::b_z) {
            this->g_i_v(25);
            (o::__ci(), o::d__v());
            return 0;
         }
         if (m::i_z) {
            this->g_i_v(34);
            (m::h_z = true);
            (m::g_z = true);
            return 0;
         }
         (m::b_i = jwrap32(jwint(m::b_i) + jwint((o::__ci(),o::a_i))));
         (m::a_z = false);
         if (((g::__ci(),g::a_Ai)[0] == 0)) {
            (m::a_c->b_b = ((int8_t)(0)));
            if (((g::__ci(),g::a_Ai)[1] != 3)) {
               (m::a_i = jwrap32(jwint(m::a_i) + jwint((o::__ci(),o::a_i))));
            }
            if (((g::__ci(),g::a_Ai)[1] != 0)) {
               if (((g::__ci(),g::a_Ai)[1] == 1)) {
                  if ((o::__ci(), o::a_i_z(1))) {
                     m::a_k->c__v();
                  }
                  if ((o::__ci(), o::a_i_z(2))) {
                     m::a_k->e__v();
                  }
                  if (((o::__ci(), o::a_i_z(15)) || (o::__ci(), o::a_i_z(7)))) {
                     m::a_k->f__v();
                  }
               }
            } else {
               bool L_var10 = false;
               if ((o::__ci(), o::a_i_z(3))) {
                  m::a_c->b__v();
                  (L_var10 = true);
               }
               if ((o::__ci(), o::a_i_z(4))) {
                  m::a_c->c__v();
                  (L_var10 = true);
               }
               if (((((o::__ci(), o::a_i_z(15)) || (o::__ci(), o::a_i_z(12))) || (o::__ci(), o::a_i_z(1))) || (o::__ci(), o::a_i_z(7)))) {
                  m::a_c->a_z_v(false);
                  (L_var10 = true);
               }
               if (L_var10) {
                  if (((c::__ci(),c::c_i) != 1)) {
                     ((c::__ci(),c::c_i) = 0);
                  }
                  ((c::__ci(),c::b_i) = 3000);
               }
            }
            (L_var1 = (g::__ci(),g::a_Ai)[4]);
            m::i__v();
            if ((((g::__ci(),g::a_Ai)[4] == 0) && (L_var1 != 0))) {
               m::a_c->g__v();
            }
            if (((m::a_c->c_d->f_i < m::a_j->j_i) && ((g::__ci(),g::a_Ai)[0] == 0))) {
               ((g::__ci(),g::a_Ai)[0] = 1);
            }
            if (((m::g_i == m::G_i) && m::c_i_z(m::f_i))) {
               ((g::__ci(),g::a_Ai)[0] = 2);
            }
            ((g::__ci(),g::a_Ai)[4] = jf2i(m::a_c->c_f));
            ((g::__ci(),g::a_Ai)[5] = jf2i(m::a_c->a_f));
            ((g::__ci(),g::a_Ai)[6] = jf2i(m::a_c->b_f));
            ((g::__ci(),g::a_Ai)[3] = m::a_c->d_i);
            (L_var1 = (o::__ci(),o::a_i));
            if ((m::H_i > 0)) {
               (m::H_i -= L_var1);
               if ((((m::I_i -= L_var1)) <= 0)) {
                  (m::I_i = jmath_abs<int32_t>(jwrap32(jwint(jrem(int32_t(m::a_Random->nextInt()),int32_t(200))) + jwint(300))));
                  (m::l_z = true);
               }
               if ((m::H_i <= 0)) {
                  (m::H_i = 0);
                  (m::I_i = 0);
                  (m::l_z = false);
                  (m::m_z = (!m::m_z));
               }
               for (int32_t L_var2 = 0; (L_var2 < m::u_As.length()); (L_var2++)) {
                  {
                     if (((o::__ci(), o::a_i_Image(((int32_t)(m::u_As[L_var2])))) != nullptr)) {
                        if (((m::m_z && (!m::l_z)) || ((!m::m_z) && m::l_z))) {
                           if ((m::b_AImage[L_var2] != nullptr)) {
                              (o::__ci(), o::a_iImage_v(((int32_t)(m::u_As[L_var2])), m::b_AImage[L_var2]));
                           }
                        } else {
                           if ((m::a_AImage[L_var2] != nullptr)) {
                              (o::__ci(), o::a_iImage_v(((int32_t)(m::u_As[L_var2])), m::a_AImage[L_var2]));
                           }
                        }
                     }
                  }
               }
            }
         } else {
            if (((g::__ci(),g::a_Ai)[0] == 1)) {
               (o::__ci(), o::c_ii_v(33, 1));
               ((g::__ci(),g::a_Ai)[0] = 3);
               (m::c_i = 3000);
               (m::d_i = m::a_c->c_d->f_i);
            } else {
               if (((g::__ci(),g::a_Ai)[0] == 2)) {
                  (o::__ci(), o::c_ii_v(34, 1));
                  ((g::__ci(),g::a_Ai)[0] = 4);
                  (m::c_i = 3000);
                  m::a_c->g__v();
                  if (m::c_i_z(m::f_i)) {
                     (m::a_c->a_z = false);
                  }
                  m::a_n->a_iiiiiii_v(20, m::a_c->c_d->c_i, m::a_c->c_d->f_i, 740, 0, 1840, 230);
               } else {
                  if (((g::__ci(),g::a_Ai)[0] == 3)) {
                     (m::c_i = jwrap32(jwint(m::c_i) - jwint((o::__ci(),o::a_i))));
                     m::a_c->e__v();
                     if ((m::c_i <= 0)) {
                        m::a_c->a_ii_v(m::h_i, m::i_i);
                        (m::c_z = true);
                        ((g::__ci(),g::a_Ai)[0] = 0);
                        (m::a_c->a_i = (-16777216));
                        (o::__ci(), o::c_ii_v(m::d__i(), (-1)));
                     }
                  } else {
                     if (((g::__ci(),g::a_Ai)[0] == 4)) {
                        (m::c_i = jwrap32(jwint(m::c_i) - jwint((o::__ci(),o::a_i))));
                        m::a_c->a_z_v(true);
                        m::i__v();
                        if ((m::c_i <= 0)) {
                           int32_t L_var13 = m::e_i_i(m::f_i);
                           int32_t L_var3 = m::d_i_i(m::f_i);
                           int32_t L_var4 = ((int32_t)(m::f_As[jwrap32(jwint((jshl(int32_t(m::f_i),2))) + jwint(3))]));
                           bool L_var5 = m::a_i_z(13);
                           bool L_var6 = m::a__z();
                           int32_t L_var7{};
                           if ((((L_var7 = ((int32_t)(((int16_t)((jdiv(int32_t(m::a_i),int32_t(1000))))))))) < 1)) {
                              (L_var7 = 1);
                           }
                           int32_t L_var8{};
                           if ((((L_var8 = jf2i((((((float)((jwrap32(jwint(m::g_i) * jwint(10000))))) * m::a_Af[m::f_i]) / ((float)(L_var7))))))) > 32767)) {
                              (L_var8 = 32767);
                           }
                           (m::p_i = ((int32_t)(((int16_t)(L_var8)))));
                           m::a_isss_v(m::f_i, ((int16_t)(m::g_i)), ((int16_t)(L_var7)), ((int16_t)(m::p_i)));
                           if ((!m::c_i_z(m::f_i))) {
                              if (m::c_i_z((L_var7 = jwrap32(jwint(m::f_i) + jwint(1))))) {
                                 (L_var7++);
                              }
                              if (((L_var7 <= 14) && (!m::b_i_z(L_var7)))) {
                                 m::e_i_v(L_var7);
                              }
                           }
                           (L_var7 = 0);
                           for (int32_t L_var17 = 0; (L_var17 < m::c_Ai.length()); (L_var17 += 2)) {
                              {
                                 int32_t L_var9{};
                                 if ((([&]() { auto __l869 = m::c__i(); auto __r870 = m::c_Ai[jwrap32(jwint(L_var17) + jwint(1))]; return (__l869 >= __r870); }()) && (!m::b_i_z((L_var9 = m::c_Ai[L_var17]))))) {
                                    m::e_i_v(L_var9);
                                    (L_var7 = jwrap32(jwint((jshr(int32_t(L_var17),1))) + jwint(1)));
                                 }
                              }
                           }
                           if (((!L_var5) && m::a_i_z(13))) {
                              (this->n_z = true);
                           }
                           if (((!L_var6) && m::a__z())) {
                              (this->o_z = true);
                           }
                           if (([&]() { auto __l871 = ((L_var8 = m::e_i_i(m::f_i))); auto __r872 = L_var13; return (__l871 > __r872); }())) {
                              (this->J_i = L_var8);
                           }
                           int32_t L_var19{};
                           if (([&]() { auto __l873 = ((L_var19 = m::d_i_i(m::f_i))); auto __r874 = L_var3; return (__l873 > __r874); }())) {
                              (this->K_i = L_var19);
                           }
                           int32_t L_var14{};
                           if (([&]() { auto __l875 = ((L_var14 = ((int32_t)(m::f_As[jwrap32(jwint((jshl(int32_t(m::f_i),2))) + jwint(3))])))); auto __r876 = L_var4; return (__l875 > __r876); }())) {
                              (this->q_z = true);
                           }
                           m::d__v();
                           if ((L_var7 > 0)) {
                              (this->p_z = true);
                              (m::a_AString = Arr<JString>({jcat(JS(u""),L_var7)}));
                              m::a_i_v(1);
                           } else {
                              this->j__v();
                           }
                        }
                     }
                  }
               }
            }
         }
         this->c__v();
         return 0;
      }
   }
   return 0;
}
int32_t m::a_ii_i(int32_t L_var1, int32_t L_var2) {
   JGraphics L_var20 = (o::__ci(), o::a__Graphics());
   if ((this->j_i == 2)) {
      if ((this->C_i < 0)) {
         this->b_Graphics_v(L_var20);
         this->e__v();
      } else {
         L_var20->setColor(m::r_Ai[this->C_i]);
         L_var20->fillRect(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
         (L_var1 = m::p_Ai[this->C_i]);
         ([&]() -> decltype(auto) { auto __p885 = ([&]() { auto __l879 = jdiv(int32_t((([&]() { auto __l877 = (o::__ci(),o::b_i); auto __r878 = (o::__ci(), o::a_ii_i(L_var1, 0)); return jwrap32(jwint(__l877) - jwint(__r878)); }()))),int32_t(2)); auto __r880 = (o::__ci(), o::a_ii_i(L_var1, 2)); return jwrap32(jwint(__l879) + jwint(__r880)); }()); auto __p886 = ([&]() { auto __l883 = jdiv(int32_t((([&]() { auto __l881 = (o::__ci(),o::c_i); auto __r882 = (o::__ci(), o::a_ii_i(L_var1, 1)); return jwrap32(jwint(__l881) - jwint(__r882)); }()))),int32_t(2)); auto __r884 = (o::__ci(), o::a_ii_i(L_var1, 3)); return jwrap32(jwint(__l883) + jwint(__r884)); }()); auto __p887 = L_var1; return (o::__ci(), o::a_iii_v(__p885, __p886, __p887)); }());
         if (([&]() { auto __l890 = ([&]() { auto __l888 = JSystem::currentTimeMillis(); auto __r889 = this->a_l; return jwrap64(jwlong(__l888) - jwlong(__r889)); }()); auto __r891 = ((int64_t)(m::q_Ai[this->C_i])); return (__l890 > __r891); }())) {
            this->e__v();
         }
      }
      return 0;
   } else {
      if ((L_var2 == 1)) {
         if ((this->j_i == 4)) {
            (o::__ci(), o::b_z_v(true));
            JGraphics L_var21 = (o::__ci(), o::a__Graphics());
            Obj L_var30 = nullptr;
            JDirectGraphics L_var31 = JDirectUtils::getDirectGraphics(L_var21);
            L_var21->setClip(0, 0, m::x_i, m::y_i);
            int32_t L_var4 = m::b_i_i(m::f_i);
            Arr<int16_t> L_var5 = m::i_As;
            Arr<int16_t> L_var6 = m::j_As;
            Arr<int16_t> L_var7 = m::k_As;
            Arr<int16_t> L_var8 = m::l_As;
            int32_t L_var9 = 5413606;
            int32_t L_var10 = 7460351;
            if ((L_var4 == 1)) {
               (L_var5 = m::m_As);
               (L_var6 = m::n_As);
               (L_var7 = m::o_As);
               (L_var8 = m::p_As);
               (L_var9 = 7263689);
               (L_var10 = 10485759);
            } else {
               if ((L_var4 == 2)) {
                  (L_var5 = m::q_As);
                  (L_var6 = m::r_As);
                  (L_var7 = m::s_As);
                  (L_var8 = m::t_As);
                  (L_var9 = 7737588);
                  (L_var10 = 131610);
               }
            }
            if (m::c_i_z(m::f_i)) {
               (L_var9 = 11796669);
               (L_var10 = 16616467);
            }
            int32_t L_var10006 = jdiv(int32_t((o::__ci(),o::c_i)),int32_t(40));
            JGraphics L_var14 = L_var21;
            int32_t L_var13 = L_var10006;
            int32_t L_var12 = (o::__ci(),o::c_i);
            int32_t L_var11 = (o::__ci(),o::b_i);
            bool L_var33 = false;
            bool L_var34 = false;
            int32_t L_var15 = (jshr(int32_t(L_var9),16) & 0xFF);
            int32_t L_var16 = (jshr(int32_t(L_var9),8) & 0xFF);
            (L_var9 &= 255);
            int32_t L_var17 = (jshr(int32_t(L_var10),16) & 0xFF);
            int32_t L_var18 = (jshr(int32_t(L_var10),8) & 0xFF);
            (L_var10 &= 255);
            int32_t L_var19 = jdiv(int32_t(65536),int32_t(L_var12));
            (L_var17 = jwrap32(jwint(jwrap32(jwint((jwrap32(jwint(L_var17) - jwint(L_var15)))) * jwint(L_var19))) * jwint(L_var13)));
            (L_var18 = jwrap32(jwint(jwrap32(jwint((jwrap32(jwint(L_var18) - jwint(L_var16)))) * jwint(L_var19))) * jwint(L_var13)));
            (L_var10 = jwrap32(jwint(jwrap32(jwint((jwrap32(jwint(L_var10) - jwint(L_var9)))) * jwint(L_var19))) * jwint(L_var13)));
            (L_var15 = jshl(int32_t(L_var15),16));
            (L_var16 = jshl(int32_t(L_var16),16));
            (L_var9 = jshl(int32_t(L_var9),16));
            for (int32_t L_var44 = 0; (L_var44 < L_var12); (L_var44 += L_var13)) {
               {
                  m::a_iGraphics_v(jwrap32(jwint(jwrap32(jwint((jshl(int32_t(jshr(int32_t(L_var15),16)),16))) + jwint((jshl(int32_t(jshr(int32_t(L_var16),16)),8))))) + jwint((jshr(int32_t(L_var9),16)))), L_var14);
                  L_var14->fillRect(0, jwrap32(jwint(L_var44) + jwint(0)), L_var11, L_var13);
                  (L_var15 += L_var17);
                  (L_var16 += L_var18);
                  (L_var9 += L_var10);
               }
            }
            m::a_Random->setSeed(((int64_t)((jwrap32(jwint(m::f_i) + jwint(1))))));
            if ((L_var4 == 2)) {
               m::a_AsiiiiiiiiGraphics_v(L_var8, 5, 100, 600, 100, (-80), 50, 2, (-1), L_var21);
               ([&]() -> decltype(auto) { auto __p892 = L_var7; auto __p893 = 20; auto __p894 = 100; auto __p895 = (o::__ci(), o::a_ii_i(((int32_t)(L_var7[0])), 0)); auto __p896 = 0; auto __p897 = (-50); auto __p898 = 0; auto __p899 = 3; auto __p900 = 1380668; auto __p901 = L_var21; return m::a_AsiiiiiiiiGraphics_v(__p892, __p893, __p894, __p895, __p896, __p897, __p898, __p899, __p900, __p901); }());
               ([&]() -> decltype(auto) { auto __p902 = L_var6; auto __p903 = 50; auto __p904 = 100; auto __p905 = (o::__ci(), o::a_ii_i(((int32_t)(L_var6[0])), 0)); auto __p906 = 0; auto __p907 = (-30); auto __p908 = 0; auto __p909 = 3; auto __p910 = 131610; auto __p911 = L_var21; return m::a_AsiiiiiiiiGraphics_v(__p902, __p903, __p904, __p905, __p906, __p907, __p908, __p909, __p910, __p911); }());
            } else {
               m::a_AsiiiiiiiiGraphics_v(L_var7, 20, 100, 200, 140, (-200), 200, 5, (-1), L_var21);
               m::a_AsiiiiiiiiGraphics_v(L_var6, 50, 100, 100, 70, (-70), 300, 5, (-1), L_var21);
               m::a_AsiiiiiiiiGraphics_v(L_var5, 80, 100, 150, 100, (-70), 300, 5, (-1), L_var21);
            }
            m::a_Random->setSeed(JSystem::currentTimeMillis());
            (j::__ci(), j::a_jGraphicsDirectGraphics_v(m::a_j, L_var21, L_var31));
            L_var21->setClip(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
            (o::__ci(), o::a_ii_v((-3), 1));
            (o::__ci(), o::b_ii_v(0, 0));
            (o::__ci(), o::a_iii_v(0, 0, 102));
            int32_t L_var22 = 0;
            (o::__ci(), o::a_iii_v((L_var22 = jwrap32(jwint(32) + jwint(m::a_iiiiz_i(32, 7, m::g_i, 4, false)))), 7, 101));
            (L_var22 += 9);
            m::a_iiiiz_i(L_var22, 7, m::G_i, 4, false);
            (o::__ci(), o::a_iii_v((o::__ci(),o::b_i), 0, 103));
            (L_var2 = jdiv(int32_t(((L_var22 = jdiv(int32_t(m::a_i),int32_t(1000))))),int32_t(60)));
            int32_t L_var3 = jrem(int32_t(L_var22),int32_t(60));
            int32_t L_var27{};
            (o::__ci(), o::a_iiii_v((L_var27 = ([&]() { auto __l912 = ((L_var22 = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint((o::__ci(),o::b_i)) - jwint(25))) - jwint(6))) - jwint(1)))); auto __r913 = m::a_iiiiz_i(L_var22, 7, L_var3, 8, true); return jwrap32(jwint(__l912) - jwint(__r913)); }())), 7, 100, 24));
            (L_var22 = jwrap32(jwint(L_var27) - jwint(5)));
            m::a_iiiiz_i(L_var22, 7, L_var2, 8, false);
            (m::l_z = false);
            bool L_var45 = false;
         }
         if ((this->a_h != nullptr)) {
            this->a_h->d__v();
         }
      } else {
         if ((L_var2 == 2)) {
            this->b_Graphics_v(L_var20);
         }
      }
      return 0;
   }
}
void m::a_Stringiiii_v(JString L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4) {
   if ((L_var1 == 1)) {
      (o::__ci(), o::a_iiii_v(L_var2, L_var3, ((((L_var4 | 16)) == 16) ? 151 : 150), L_var4));
   } else {
      (o::__ci(), o::a_ii_v((-3), 3));
      (o::__ci(), o::b_ii_v(0, 16742400));
      (o::__ci(), o::b_ii_v(1, 0));
      ([&]() -> decltype(auto) { auto __p914 = L_var0; auto __p915 = 0; auto __p916 = L_var0.length(); auto __p917 = L_var2; auto __p918 = L_var3; auto __p919 = L_var4; return (o::__ci(), o::a_Stringiiiii_v(__p914, __p915, __p916, __p917, __p918, __p919)); }());
   }
}
int32_t m::b__i() {
   return jwrap32(jwint((o::__ci(), o::a_i_i((-3)))) + jwint(4));
}
void m::c_i_v(int32_t L_var1) {
   if ((L_var1 == 1)) {
      (o::__ci(), o::e_i_v(9));
      (o::__ci(), o::e_i_v(14));
      (o::__ci(), o::e_i_v(15));
      (o::__ci(), o::e_i_v(37));
      (o::__ci(), o::e_i_v(36));
      (o::__ci(), o::e_i_v((-1)));
      (o::__ci(), o::e_i_v((-2)));
      (o::__ci(), o::e_i_v((-3)));
      (o::__ci(), o::a_i_v(0));
   }
   if (((L_var1 == 3) && (this->j_i == 4))) {
      (m::b_z = true);
      if (m::g_z) {
         (m::i_z = true);
         (m::g_z = false);
         this->b__v();
         return;
      }
      if ((!m::i_z)) {
         (m::a_String = nullptr);
      }
   }
}
int32_t m::b_ii_i(int32_t L_var1, int32_t L_var2) {
   if (((L_var1 != 17) && (L_var1 != 25))) {
      (m::o_i = 0);
   }
   {
      switch (L_var1) {
      case 0:
      {
         (o::__ci(), o::a_i_v(2));
         return 0;
      }
      case 1:
      {
         if (((L_var2 >= 0) && (L_var2 < m::o_Ai.length()))) {
            if ((L_var2 == 0)) {
               (this->C_i = (-1));
               (this->j_i = 2);
            }
            (o::__ci(), o::e_i_v(m::o_Ai[L_var2]));
            return jwrap32(jwint(L_var2) + jwint(1));
         } else {
            if ((L_var2 == m::o_Ai.length())) {
               m::f__v();
               if ((o::__ci(), o::c__z())) {
                  (o::__ci(), o::g_i_v(0));
               }
               Arr<int8_t> L_var14 = (o::__ci(), o::a_String_Ab(JS(u"game")));
               (L_var2 = 0);
               if ((L_var14 != nullptr)) {
                  for (int32_t L_var31 = 0; (L_var31 < m::f_As.length()); (L_var31++)) {
                     {
                        ([&]() -> decltype(auto) { auto& __a922 = m::f_As[L_var31]; auto __v923 = ((int16_t)((([&]() { auto __l920 = jshl(int32_t(((L_var14[(L_var2++)] & 255))),8); auto __r921 = (L_var14[(L_var2++)] & 255); return (__l920 | __r921); }())))); return (__a922 = __v923); }());
                     }
                  }
                  if ((!m::a_i_z(13))) {
                     for (int32_t L_var32 = 14; (L_var32 >= 0); (L_var32--)) {
                        {
                           if ((m::b_i_z(L_var32) && (!m::c_i_z(L_var32)))) {
                              (m::k_i = L_var32);
                              break;
                           }
                        }
                     }
                  }
               } else {
                  for (int32_t L_var33 = 0; (L_var33 < m::f_As.length()); (L_var33++)) {
                     {
                        (m::f_As[L_var33] = ((int16_t)(0)));
                     }
                  }
                  m::e_i_v(0);
               }
               return 0;
            }
            return 0;
         }
      }
      case 2:
      {
         if ((L_var2 == 0)) {
            return 1;
         } else {
            if ((L_var2 == 1)) {
               return 2;
            } else {
               if ((L_var2 != 2)) {
                  return 0;
               }
               if (((this->a_h != nullptr) && (this->a_h->a_i != 14))) {
                  this->g_i_v(19);
               } else {
                  (o::__ci(), o::a_z_v(true));
                  (o::__ci(), o::a_i_v(1));
               }
               return 0;
            }
         }
      }
      case 3:
      case 4:
      case 7:
      case 8:
      case 9:
      case 10:
      case 12:
      case 13:
      case 14:
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 23:
      case 24:
      case 25:
      case 26:
      case 28:
      case 29:
      case 30:
      case 31:
      case 32:
      case 33:
      case 34:
      case 35:
      default:
      {
         return 0;
      }
      case 5:
      {
         if ((L_var2 == 0)) {
            (o::__ci(), o::d__v());
            m::f__v();
            return 1;
         } else {
            if ((L_var2 == 1)) {
               (this->j_i = 3);
               this->g_i_v(m::A_i);
               (o::__ci(), o::c_ii_v(28, (-1)));
               return 0;
            }
            return 0;
         }
      }
      case 6:
      case 15:
      {
         if ((L_var2 == 0)) {
            (o::__ci(), o::d__v());
            (o::__ci(), o::f_i_v(10));
            (o::__ci(), o::f_i_v(13));
            (o::__ci(), o::e_i_v(((int32_t)(m::v_As[m::f_i]))));
            (o::__ci(), o::e_i_v(((int32_t)(m::v_As[15]))));
            (o::__ci(), o::e_i_v(2));
            (o::__ci(), o::e_i_v(1));
            (o::__ci(), o::e_i_v(6));
            (o::__ci(), o::e_i_v(5));
            (o::__ci(), o::e_i_v(24));
            (o::__ci(), o::e_i_v(0));
            (o::__ci(), o::e_i_v(3));
            (o::__ci(), o::e_i_v(26));
            (o::__ci(), o::e_i_v(20));
            (o::__ci(), o::e_i_v(19));
            (o::__ci(), o::e_i_v(16));
            (o::__ci(), o::e_i_v(25));
            (o::__ci(), o::e_i_v(27));
            (o::__ci(), o::e_i_v(21));
            (o::__ci(), o::e_i_v(23));
            (o::__ci(), o::e_i_v(22));
            if ((((L_var1 = m::b_i_i(m::f_i))) == 0)) {
               (o::__ci(), o::e_i_v(12));
               (o::__ci(), o::e_i_v(17));
               (o::__ci(), o::e_i_v(18));
            }
            if ((L_var1 == 1)) {
               (o::__ci(), o::e_i_v(11));
               (o::__ci(), o::e_i_v(17));
               (o::__ci(), o::e_i_v(18));
            }
            if ((L_var1 == 2)) {
               (o::__ci(), o::e_i_v(8));
               (o::__ci(), o::e_i_v(4));
               (o::__ci(), o::e_i_v(17));
            }
            (m::a_Graphics = ((m::a_Image = JImage::createImage(jwrap32(jwint((c::__ci(),c::b_Ai)[0]) * jwint(3)), jwrap32(jwint((c::__ci(),c::b_Ai)[0]) * jwint(3)))))->getGraphics());
            (m::a_Ai = newArr<int32_t>(([&]() { auto __l924 = m::a_Image->getWidth(); auto __r925 = m::a_Image->getHeight(); return jwrap32(jwint(__l924) * jwint(__r925)); }())));
            (m::b_Graphics = ((m::b_Image = JImage::createImage(112, 26)))->getGraphics());
            (m::b_Ai = newArr<int32_t>(([&]() { auto __l926 = m::b_Image->getWidth(); auto __r927 = m::b_Image->getHeight(); return jwrap32(jwint(__l926) * jwint(__r927)); }())));
            return 1;
         } else {
            if ((L_var2 != 1)) {
               return 0;
            }
            if ((!this->k_z)) {
               (this->k_z = true);
               (m::b_z = false);
               (o::__ci(), o::b_i_v(2));
               (o::__ci(), o::c_i_v(jdiv(int32_t(150),int32_t((o::__ci(), o::a__i())))));
               for (int32_t L_var15 = 0; (L_var15 < 5); (L_var15++)) {
                  {
                     (m::n_Ai[L_var15] = (-1));
                  }
               }
               (m::z_i = 0);
               (m::g_z = false);
               (m::i_z = false);
               (m::d_z = m::a__z());
               ((j::__ci(),j::p_i) = 90);
               ((j::__ci(),j::q_i) = 140);
               (m::a_i = 0);
               (m::b_i = 0);
               (m::g_i = 0);
               (m::p_i = 0);
               (m::g_z = false);
               (m::a_z = false);
               (m::h_z = false);
               ((j::__ci(),j::g_d)->c_i = jshl(int32_t((o::__ci(),o::b_i)),15));
               ((j::__ci(),j::g_d)->f_i = jshl(int32_t((o::__ci(),o::c_i)),15));
               Arr<int8_t> L_var16 = jcast<Arr<int8_t>>((o::__ci(), o::a_i_Object(((int32_t)(m::v_As[15])))));
               int32_t L_var3 = 8;
               (m::a_Aj = newArr<j*>((j::__ci(), j::a_Abi_s(L_var16, 8))));
               (L_var3 += 6);
               (L_var3++);
               int32_t L_var10 = ((int32_t)(L_var16[14]));
               int32_t L_var4 = 0;
               int32_t L_var5 = 0;
               while ((L_var10 != 127)) {
                  {
                     int32_t L_var6 = ((int32_t)((j::__ci(), j::a_Abi_s(L_var16, L_var3))));
                     (L_var3 += 2);
                     {
                        p* L_var11{};
                        switch (L_var10) {
                        case 4:
                        {
                           ((L_var11 = (p::__ci(), new p())))->a_s_v(((int16_t)(L_var4)));
                           L_var11->a_Abi_i(L_var16, L_var3);
                           if ((L_var11->a_i > L_var5)) {
                              (L_var5 = L_var11->a_i);
                           }
                           ([&]() -> decltype(auto) { auto& __a928 = m::a_Aj[(L_var4++)]; auto __v929 = L_var11; return (__a928 = static_cast<j*>(__v929)); }());
                        }
                        default:
                        {
                           (L_var3 += L_var6);
                           (L_var10 = ((int32_t)(L_var16[(L_var3++)])));
                        }
                        }
                     }
                  }
               }
               (L_var10 = L_var5);
               Arr<int8_t> L_var17{};
               if ((((L_var17 = jcast<Arr<int8_t>>((o::__ci(), o::a_i_Object(((int32_t)(m::v_As[m::f_i]))))))) != nullptr)) {
                  int32_t L_var25 = 8;
                  (m::b_Aj = newArr<j*>((m::D_i = ((int32_t)((j::__ci(), j::a_Abi_s(L_var17, 8)))))));
                  (m::a_Ag = newArr<g*>((m::E_i = ((int32_t)((j::__ci(), j::a_Abi_s(L_var17, 12)))))));
                  (L_var25 += 6);
                  (L_var25++);
                  int32_t L_var34 = ((int32_t)(L_var17[14]));
                  int32_t L_var43 = 0;
                  int32_t L_var53 = 0;
                  for ((m::G_i = 0); (L_var34 != 127); (L_var34 = ((int32_t)(L_var17[(L_var25++)])))) {
                     {
                        int32_t L_var7 = ((int32_t)((j::__ci(), j::a_Abi_s(L_var17, L_var25))));
                        (L_var25 += 2);
                        {
                           p* L_var41{};
                           g* L_var8{};
                           i* L_var40{};
                           k* L_var39{};
                           e* L_var38{};
                           a* L_var37{};
                           c* L_var36{};
                           l* L_var35{};
                           switch (L_var34) {
                           case 4:
                           {
                              ((L_var41 = (p::__ci(), new p())))->a_s_v(((int16_t)(L_var43)));
                              L_var41->a_Abi_i(L_var17, L_var25);
                              if ((L_var41->a_i > L_var10)) {
                                 (L_var10 = L_var41->a_i);
                              }
                              ([&]() -> decltype(auto) { auto& __a930 = m::b_Aj[(L_var43++)]; auto __v931 = L_var41; return (__a930 = static_cast<j*>(__v931)); }());
                              break;
                           }
                           case 5:
                           case 7:
                           default:
                           {
                              ([&]() -> decltype(auto) { auto& __a932 = m::b_Aj[L_var43]; auto __v933 = (j::__ci(), new j()); return (__a932 = __v933); }());
                              m::b_Aj[L_var43]->a_s_v(((int16_t)(L_var43)));
                              m::b_Aj[(L_var43++)]->a_Abi_i(L_var17, L_var25);
                              break;
                           }
                           case 6:
                           {
                              ((L_var8 = (g::__ci(), new g())))->a_s_v(((int16_t)(L_var43)));
                              L_var8->a_Abi_i(L_var17, L_var25);
                              ([&]() -> decltype(auto) { auto& __a934 = m::b_Aj[(L_var43++)]; auto __v935 = L_var8; return (__a934 = static_cast<j*>(__v935)); }());
                              ([&]() -> decltype(auto) { auto& __a936 = m::a_Ag[(L_var53++)]; auto __v937 = L_var8; return (__a936 = __v937); }());
                              break;
                           }
                           case 8:
                           {
                              ((m::a_c = (c::__ci(), new c(true))))->a_s_v(((int16_t)(L_var43)));
                              m::a_c->a_Abi_i(L_var17, L_var25);
                              m::a_c->a__v();
                              ([&]() -> decltype(auto) { auto& __a938 = m::b_Aj[(L_var43++)]; auto __v939 = m::a_c; return (__a938 = static_cast<j*>(__v939)); }());
                              (m::h_i = m::a_c->c_d->c_i);
                              (m::i_i = m::a_c->c_d->f_i);
                              break;
                           }
                           case 9:
                           {
                              ([&]() -> decltype(auto) { auto& __a940 = m::b_Aj[L_var43]; auto __v941 = (r::__ci(), new r()); return (__a940 = static_cast<j*>(__v941)); }());
                              m::b_Aj[L_var43]->a_s_v(((int16_t)(L_var43)));
                              m::b_Aj[L_var43]->a_Abi_i(L_var17, L_var25);
                              m::b_Aj[(L_var43++)]->a__v();
                              break;
                           }
                           case 10:
                           {
                              ((L_var40 = (i::__ci(), new i())))->a_s_v(((int16_t)(L_var43)));
                              L_var40->a_Abi_i(L_var17, L_var25);
                              L_var40->a__v();
                              if ((L_var40->a_i > L_var10)) {
                                 (L_var10 = L_var40->a_i);
                              }
                              ([&]() -> decltype(auto) { auto& __a942 = m::b_Aj[(L_var43++)]; auto __v943 = L_var40; return (__a942 = static_cast<j*>(__v943)); }());
                              break;
                           }
                           case 11:
                           {
                              ((L_var39 = (k::__ci(), new k())))->a_s_v(((int16_t)(L_var43)));
                              L_var39->a_Abi_i(L_var17, L_var25);
                              L_var39->a__v();
                              ([&]() -> decltype(auto) { auto& __a944 = m::b_Aj[(L_var43++)]; auto __v945 = L_var39; return (__a944 = static_cast<j*>(__v945)); }());
                              break;
                           }
                           case 12:
                           {
                              ((L_var38 = (e::__ci(), new e())))->a_s_v(((int16_t)(L_var43)));
                              L_var38->a_Abi_i(L_var17, L_var25);
                              L_var38->a__v();
                              ([&]() -> decltype(auto) { auto& __a946 = m::b_Aj[(L_var43++)]; auto __v947 = L_var38; return (__a946 = static_cast<j*>(__v947)); }());
                              break;
                           }
                           case 13:
                           {
                              ((L_var37 = (a::__ci(), new a())))->a_s_v(((int16_t)(L_var43)));
                              L_var37->a_Abi_i(L_var17, L_var25);
                              L_var37->a__v();
                              ([&]() -> decltype(auto) { auto& __a948 = m::b_Aj[(L_var43++)]; auto __v949 = L_var37; return (__a948 = static_cast<j*>(__v949)); }());
                              (m::G_i++);
                              break;
                           }
                           case 14:
                           {
                              ((L_var36 = (c::__ci(), new c(false))))->a_s_v(((int16_t)(L_var43)));
                              L_var36->a_Abi_i(L_var17, L_var25);
                              L_var36->a__v();
                              ([&]() -> decltype(auto) { auto& __a950 = m::b_Aj[(L_var43++)]; auto __v951 = L_var36; return (__a950 = static_cast<j*>(__v951)); }());
                              break;
                           }
                           case 15:
                           {
                              ((L_var35 = (l::__ci(), new l())))->a_s_v(((int16_t)(L_var43)));
                              L_var35->a_Abi_i(L_var17, L_var25);
                              L_var35->a__v();
                              ([&]() -> decltype(auto) { auto& __a952 = m::b_Aj[(L_var43++)]; auto __v953 = L_var35; return (__a952 = static_cast<j*>(__v953)); }());
                              (m::G_i++);
                           }
                           }
                        }
                        (L_var25 += L_var7);
                     }
                  }
                  (j::__ci(), j::a_Aj_v(m::b_Aj));
                  (m::a_j = m::b_Aj[0]);
                  (m::b_Aj = nullptr);
                  ((m::a_a = (a::__ci(), new a())))->a_s_v(((int16_t)(((L_var43++)))));
                  j* L_var30 = m::a_j;
                  a* L_var18 = m::a_a;
                  m::a_a->b_j_v(L_var30);
                  (L_var18->c_d->a_i = 65536);
                  (L_var18->c_d->b_i = 0);
                  (L_var18->c_d->c_i = J_Integer_MAX_VALUE);
                  (L_var18->c_d->d_i = 0);
                  (L_var18->c_d->e_i = 65536);
                  (L_var18->c_d->f_i = J_Integer_MAX_VALUE);
                  L_var18->b_d->a_d_v(L_var18->c_d);
                  L_var18->a__v();
                  m::c_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::c_n->c_j_v(m::a_j);
                  m::b_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::b_n->c_j_v(m::a_j);
                  m::e_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::e_n->c_j_v(m::a_j);
                  m::f_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::f_n->c_j_v(m::a_j);
                  m::g_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::g_n->c_j_v(m::a_j);
                  m::a_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::a_n->c_j_v(m::a_j);
                  m::d_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::d_n->c_j_v(m::a_j);
                  m::h_n->a_s_v(((int16_t)(((L_var43++)))));
                  m::h_n->c_j_v(m::a_j);
                  m::i_n->a_s_v(((int16_t)(L_var43)));
                  m::i_n->c_j_v(m::a_j);
                  ((p::__ci(),p::a_Ai) = newArr<int32_t>(L_var10));
                  ((p::__ci(),p::b_Ai) = newArr<int32_t>(L_var10));
                  ([&]() -> decltype(auto) { auto& __a954 = (((g::__ci(),g::a_Ai) = newArr<int32_t>(73)))[1]; auto __v955 = 0; return (__a954 = __v955); }());
                  ((g::__ci(),g::a_Ai)[0] = 0);
                  ((g::__ci(),g::a_Ai)[2] = 0);
                  ((g::__ci(),g::a_Ai)[7] = 0);
                  (o::__ci(), o::f_i_v(((int32_t)(m::v_As[m::f_i]))));
                  (o::__ci(), o::f_i_v(((int32_t)(m::v_As[15]))));
                  ((j::__ci(),j::a_j) = static_cast<j*>(m::a_c));
                  (j::__ci(), j::m__v());
                  (m::F_i = (j::__ci(),j::f_d)->f_i);
                  m::g__v();
                  (m::b_n->a_i = (-1));
                  (m::c_n->a_i = (-1));
                  (m::e_n->a_i = (-1));
                  (m::f_n->a_i = (-1));
                  (m::g_n->a_i = (-1));
                  (m::a_n->a_i = (-1));
                  (m::d_n->a_i = (-1));
                  (m::h_n->a_i = (-1));
                  (m::i_n->a_i = (-1));
                  (m::a_c->a_i = (-16777216));
                  bool L_var54 = true;
                  for (int32_t L_var42 = 0; (L_var42 < m::c_Ai.length()); (L_var42 += 2)) {
                     {
                        int32_t L_var55{};
                        if (m::a_i_z((L_var55 = m::c_Ai[L_var42]))) {
                           (L_var54 = false);
                        }
                     }
                  }
                  if ((L_var54 && m::c_i_z(m::f_i))) {
                     m::a_i_v(11);
                  }
                  ((c::__ci(),c::c_i) = 0);
                  ((c::__ci(),c::b_i) = 3000);
               }
            }
            (this->j_i = 4);
            this->b__v();
            if ((!m::b_z)) {
               (o::__ci(), o::c_ii_v(m::d__i(), (-1)));
            }
            return 0;
         }
      }
      case 11:
      {
         for (int32_t L_var9 = 0; (L_var9 < m::f_As.length()); (L_var9++)) {
            {
               if ((jrem(int32_t((jwrap32(jwint(L_var9) + jwint(1)))),int32_t(4)) != 0)) {
                  (m::f_As[L_var9] = ((int16_t)(0)));
               }
            }
         }
         m::e_i_v(0);
         (m::k_i = 0);
         m::d__v();
         (this->k_z = false);
         this->g_i_v(18);
         return 0;
      }
      case 21:
      case 22:
      {
         (m::o_i = this->b_h->a__i());
         this->g_i_v(L_var1);
         return 0;
      }
      case 27:
      {
         return 0;
      }
      case 36:
      {
         if ((L_var2 == 0)) {
            (o::__ci(), o::f_i_v(m::o_Ai[jwrap32(jwint(m::o_Ai.length()) - jwint(1))]));
            return 1;
         } else {
            if ((L_var2 == 1)) {
               (this->j_i = 3);
               (o::__ci(), o::c_ii_v(28, (-1)));
               this->g_i_v(17);
               return 0;
            } else {
               return 0;
            }
         }
      }
      }
   }
}
int32_t m::d__i() {
   int32_t L_var0 = 31;
   if ((m::b_i_i(m::f_i) == 1)) {
      (L_var0 = 30);
   }
   if ((m::b_i_i(m::f_i) == 0)) {
      (L_var0 = 29);
   }
   if ((((m::f_i == 4) || (m::f_i == 9)) || (m::f_i == 14))) {
      (L_var0 = 35);
   }
   if ((((m::f_i == 3) || (m::f_i == 8)) || (m::f_i == 13))) {
      (L_var0 = 32);
   }
   return L_var0;
}
int32_t m::b_i_i(int32_t L_var0) {
   int32_t L_var1 = 2;
   if ((L_var0 <= 9)) {
      (L_var1 = 1);
   }
   if ((L_var0 <= 4)) {
      (L_var1 = 0);
   }
   return L_var1;
}
void m::d_i_v(int32_t L_var1) {
   if (((L_var1 != 17) && (L_var1 != 25))) {
      (m::o_i = 0);
   }
   {
      switch (L_var1) {
      case 2:
      case 5:
      case 6:
      case 11:
      case 15:
      case 21:
      case 22:
      case 27:
      {
         (o::__ci(), o::a_i_v(L_var1));
         return;
      }
      case 3:
      case 4:
      case 12:
      case 14:
      case 16:
      case 34:
      case 36:
      default:
      {
         break;
      }
      case 8:
      {
         (m::b_z = false);
         this->b__v();
         if ((!m::b_z)) {
            (o::__ci(), o::c_ii_v(m::d__i(), (-1)));
         }
         break;
      }
      case 9:
      {
         (o::__ci(), o::a__v());
         return;
      }
      case 10:
      case 20:
      case 28:
      case 29:
      case 30:
      {
         (m::o_i = this->b_h->a__i());
      }
      case 17:
      case 18:
      case 19:
      case 23:
      case 24:
      case 25:
      case 26:
      case 31:
      case 32:
      case 33:
      {
         this->g_i_v(L_var1);
         return;
      }
      case 13:
      {
         return;
      }
      case 35:
      {
         (m::g_z = false);
         this->b__v();
         if (this->p_z) {
            (this->p_z = false);
            this->j__v();
            return;
         }
         break;
      }
      case 37:
      {
         m::h__v();
      }
      case 7:
      {
         if (m::b_i_z(m::k_i)) {
            (m::m_i = m::n_i);
            (this->k_z = false);
            (m::f_i = m::k_i);
            (o::__ci(), o::a_i_v(6));
            return;
         }
      }
      }
   }
}
void m::d__v() {
   Arr<int8_t> L_var0 = newArr<int8_t>(jshl(int32_t(m::f_As.length()),1));
   for (int32_t L_var1 = 0; (L_var1 < m::f_As.length()); (L_var1++)) {
      {
         (L_var0[jshl(int32_t(L_var1),1)] = ((int8_t)((jshr(int32_t(m::f_As[L_var1]),8)))));
         (L_var0[jwrap32(jwint((jshl(int32_t(L_var1),1))) + jwint(1))] = ((int8_t)(m::f_As[L_var1])));
      }
   }
   (o::__ci(), o::a_StringAb_v(JS(u"game"), L_var0));
}
void m::b_Graphics_v(JGraphics L_var1) {
   if (m::j_z) {
      L_var1->setColor(7352325);
      L_var1->fillRect(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
      L_var1->setColor(0);
      L_var1->fillRect(jdiv(int32_t((jwrap32(jwint((o::__ci(),o::b_i)) - jwint(60)))),int32_t(2)), jdiv(int32_t((jwrap32(jwint((o::__ci(),o::c_i)) - jwint(10)))),int32_t(2)), 60, 10);
      L_var1->setColor(4660480);
      L_var1->fillRect(jwrap32(jwint(jdiv(int32_t((jwrap32(jwint((o::__ci(),o::b_i)) - jwint(60)))),int32_t(2))) + jwint(1)), jwrap32(jwint(jdiv(int32_t((jwrap32(jwint((o::__ci(),o::c_i)) - jwint(10)))),int32_t(2))) + jwint(1)), 58, 8);
      L_var1->setColor(11460924);
      L_var1->fillRect(jwrap32(jwint(jdiv(int32_t((jwrap32(jwint((o::__ci(),o::b_i)) - jwint(60)))),int32_t(2))) + jwint(1)), jwrap32(jwint(jdiv(int32_t((jwrap32(jwint((o::__ci(),o::c_i)) - jwint(10)))),int32_t(2))) + jwint(1)), jwrap32(jwint(jdiv(int32_t(jwrap32(jwint(60) * jwint(this->B_i))),int32_t(20))) - jwint(2)), 8);
      (this->B_i++);
      if ((this->B_i > 20)) {
         (this->B_i = 0);
         return;
      }
   } else {
      L_var1->setColor(16777215);
      L_var1->fillRect(0, 0, (o::__ci(),o::b_i), (o::__ci(),o::c_i));
   }
}
void m::e__v() {
   if ((jwrap32(jwint(this->C_i) + jwint(1)) < m::o_Ai.length())) {
      if ((!(o::__ci(), o::b_i_z(m::o_Ai[jwrap32(jwint(this->C_i) + jwint(1))])))) {
         return;
      }
      (m::j_z = true);
      (this->C_i++);
      ([&]() -> decltype(auto) { auto& __a956 = this->a_l; auto __v957 = JSystem::currentTimeMillis(); return (__a956 = __v957); }());
      if ((jwrap32(jwint(this->C_i) - jwint(1)) > (-1))) {
         (o::__ci(), o::f_i_v(m::o_Ai[jwrap32(jwint(this->C_i) - jwint(1))]));
         return;
      }
   } else {
      (o::__ci(), o::a_i_v(36));
   }
}
void m::f__v() {
   (m::a_Image = nullptr);
   (m::a_Graphics = nullptr);
   (m::a_Ai = nullptr);
   (m::b_Image = nullptr);
   (m::b_Graphics = nullptr);
   (m::b_Ai = nullptr);
   ((p::__ci(),p::a_Ai) = nullptr);
   ((p::__ci(),p::b_Ai) = nullptr);
   (m::a_j = nullptr);
   ((j::__ci(),j::a_j) = nullptr);
   (m::a_c = nullptr);
   (m::a_Ag = nullptr);
   (m::a_k = nullptr);
   (m::a_AImage = nullptr);
   (m::b_AImage = nullptr);
   (o::__ci(), o::f_i_v(2));
   (o::__ci(), o::f_i_v(1));
   (o::__ci(), o::f_i_v(6));
   (o::__ci(), o::f_i_v(5));
   (o::__ci(), o::f_i_v(24));
   (o::__ci(), o::f_i_v(0));
   (o::__ci(), o::f_i_v(3));
   (o::__ci(), o::f_i_v(26));
   (o::__ci(), o::f_i_v(20));
   (o::__ci(), o::f_i_v(19));
   (o::__ci(), o::f_i_v(16));
   (o::__ci(), o::f_i_v(25));
   (o::__ci(), o::f_i_v(22));
   (o::__ci(), o::f_i_v(27));
   (o::__ci(), o::f_i_v(21));
   (o::__ci(), o::f_i_v(23));
   int32_t L_var0{};
   if ((((L_var0 = m::b_i_i(m::f_i))) == 0)) {
      (o::__ci(), o::f_i_v(12));
      (o::__ci(), o::f_i_v(17));
      (o::__ci(), o::f_i_v(18));
   }
   if ((L_var0 == 1)) {
      (o::__ci(), o::f_i_v(11));
      (o::__ci(), o::f_i_v(17));
      (o::__ci(), o::f_i_v(18));
   }
   if ((L_var0 == 2)) {
      (o::__ci(), o::f_i_v(8));
      (o::__ci(), o::f_i_v(4));
   }
   (o::__ci(), o::e_i_v(10));
   (o::__ci(), o::e_i_v(13));
}
void m::g__v() {
   (m::H_i = 0);
   (m::I_i = 0);
   (m::l_z = false);
   (m::m_z = false);
   try {
      (m::a_AImage = newArr<JImage>(m::u_As.length()));
      (m::b_AImage = newArr<JImage>(m::u_As.length()));
      for (int32_t L_var1 = 0; (L_var1 < m::u_As.length()); (L_var1++)) {
         {
            if (((o::__ci(), o::a_i_Image(((int32_t)(m::u_As[L_var1])))) != nullptr)) {
               ([&]() -> decltype(auto) { auto& __a958 = m::a_AImage[L_var1]; auto __v959 = (o::__ci(), o::a_i_Image(((int32_t)(m::u_As[L_var1])))); return (__a958 = __v959); }());
               ([&]() -> decltype(auto) { auto& __a960 = m::b_AImage[L_var1]; auto __v961 = JImage::createImage(m::a_AImage[L_var1]); return (__a960 = __v961); }());
               Arr<int32_t> L_var0 = newArr<int32_t>(([&]() { auto __l962 = m::b_AImage[L_var1]->getWidth(); auto __r963 = m::b_AImage[L_var1]->getHeight(); return jwrap32(jwint(__l962) * jwint(__r963)); }()));
               ([&]() -> decltype(auto) { auto __p964 = L_var0; auto __p965 = 0; auto __p966 = m::b_AImage[L_var1]->getWidth(); auto __p967 = 0; auto __p968 = 0; auto __p969 = m::b_AImage[L_var1]->getWidth(); auto __p970 = m::b_AImage[L_var1]->getHeight(); return m::b_AImage[L_var1]->getRGB(__p964, __p965, __p966, __p967, __p968, __p969, __p970); }());
               Arr<int32_t> L_var2 = L_var0;
               for (int32_t L_var9 = 0; (L_var9 < L_var2.length()); (L_var9++)) {
                  {
                     int32_t L_var6 = jushr(int32_t(L_var2[L_var9]),24);
                     int32_t L_var3 = (jshr(int32_t(L_var2[L_var9]),16) & 0xFF);
                     int32_t L_var4 = (jshr(int32_t(L_var2[L_var9]),8) & 0xFF);
                     int32_t L_var5 = (L_var2[L_var9] & 0xFF);
                     int32_t L_var13 = jshr(int32_t(jwrap32(jwint(L_var4) + jwint(L_var5))),1);
                     int32_t L_var15 = jshr(int32_t(jwrap32(jwint(L_var3) + jwint(L_var5))),1);
                     (L_var5 = jshr(int32_t(jwrap32(jwint(L_var3) + jwint(L_var4))),1));
                     (L_var2[L_var9] = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint((jshl(int32_t(L_var6),24))) + jwint((jshl(int32_t(L_var13),16))))) + jwint((jshl(int32_t(L_var15),8))))) + jwint(L_var5)));
                  }
               }
               int32_t L_var12 = m::b_AImage[L_var1]->getWidth();
               int32_t L_var14 = m::b_AImage[L_var1]->getHeight();
               ([&]() -> decltype(auto) { auto& __a971 = m::b_AImage[L_var1]; auto __v972 = JImage::createRGBImage(L_var0, L_var12, L_var14, true); return (__a971 = __v972); }());
            }
         }
      }
      Obj L_var11 = nullptr;
   }
   catch (JException& L_var10) {
   }
}
int32_t m::c_i_i(int32_t L_var0) {
   if (((m::m_z && (!m::l_z)) || ((!m::m_z) && m::l_z))) {
      int32_t L_var1 = jushr(int32_t(L_var0),24);
      int32_t L_var2 = (jshr(int32_t(L_var0),16) & 0xFF);
      int32_t L_var3 = (jshr(int32_t(L_var0),8) & 0xFF);
      (L_var0 &= 255);
      int32_t L_var8 = jshr(int32_t(jwrap32(jwint(L_var3) + jwint(L_var0))),1);
      int32_t L_var9 = jshr(int32_t(jwrap32(jwint(L_var2) + jwint(L_var0))),1);
      (L_var0 = jshr(int32_t(jwrap32(jwint(L_var2) + jwint(L_var3))),1));
      (L_var0 = jwrap32(jwint(jwrap32(jwint(jwrap32(jwint((jshl(int32_t(L_var1),24))) + jwint((jshl(int32_t(L_var8),16))))) + jwint((jshl(int32_t(L_var9),8))))) + jwint(L_var0)));
   }
   return L_var0;
}
void m::a_iGraphics_v(int32_t L_var0, JGraphics L_var1) {
   if (((m::m_z && (!m::l_z)) || ((!m::m_z) && m::l_z))) {
      int32_t L_var2 = (jshr(int32_t(L_var0),16) & 0xFF);
      int32_t L_var3 = (jshr(int32_t(L_var0),8) & 0xFF);
      (L_var0 &= 255);
      int32_t L_var8 = jshr(int32_t(jwrap32(jwint(L_var3) + jwint(L_var0))),1);
      int32_t L_var9 = jshr(int32_t(jwrap32(jwint(L_var2) + jwint(L_var0))),1);
      (L_var0 = jshr(int32_t(jwrap32(jwint(L_var2) + jwint(L_var3))),1));
      (L_var0 = jwrap32(jwint(jwrap32(jwint((jshl(int32_t(L_var8),16))) + jwint((jshl(int32_t(L_var9),8))))) + jwint(L_var0)));
   }
   L_var1->setColor(L_var0);
}
void m::a_AsiiiiiiiiGraphics_v(Arr<int16_t> L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, int32_t L_var8, JGraphics L_var9) {
   (m::s_Ai[0] = 0);
   (L_var2 = 0);
   if ((L_var6 != 0)) {
      (L_var2 = ([&]() { auto __l973 = m::a_Random->nextInt(); auto __r974 = L_var6; return jrem(int32_t(__l973),int32_t(__r974)); }()));
   }
   (m::t_Ai[0] = jwrap32(jwint(L_var5) + jwint(L_var2)));
   for (int32_t L_var10 = 1; (L_var10 < jwrap32(jwint(L_var7) + jwint(1))); (L_var10++)) {
      {
         (L_var2 = 0);
         if ((L_var4 != 0)) {
            (L_var2 = jmath_abs<int32_t>(([&]() { auto __l975 = m::a_Random->nextInt(); auto __r976 = L_var4; return jrem(int32_t(__l975),int32_t(__r976)); }())));
         }
         (m::s_Ai[L_var10] = jwrap32(jwint(jwrap32(jwint(m::s_Ai[jwrap32(jwint(L_var10) - jwint(1))]) + jwint(L_var2))) + jwint(L_var3)));
         (L_var2 = 0);
         if ((L_var6 != 0)) {
            (L_var2 = ([&]() { auto __l977 = m::a_Random->nextInt(); auto __r978 = L_var6; return jrem(int32_t(__l977),int32_t(__r978)); }()));
         }
         (m::t_Ai[L_var10] = jwrap32(jwint(L_var5) + jwint(L_var2)));
         ([&]() -> decltype(auto) { auto& __a981 = m::u_Ai[L_var10]; auto __v982 = jmath_abs<int32_t>(([&]() { auto __l979 = m::a_Random->nextInt(); auto __r980 = L_var0.length(); return jrem(int32_t(__l979),int32_t(__r980)); }())); return (__a981 = __v982); }());
      }
   }
   int32_t L_var17{};
   (L_var2 = ([&]() { auto __l983 = ((L_var17 = m::s_Ai[L_var7])); auto __r984 = jrem(int32_t(jdiv(int32_t(jwrap32(jwint((jshr(int32_t(jwrap32(jwint((jwrap32(jwint((jshr(int32_t((j::__ci(),j::f_d)->c_i),16))) + jwint(33000)))) * jwint((j::__ci(),j::g_d)->a_i))),16))) * jwint(L_var1))),int32_t(100))),int32_t(L_var17)); return jwrap32(jwint(__l983) - jwint(__r984)); }()));
   (L_var1 = jwrap32(jwint(jdiv(int32_t(jwrap32(jwint((jshr(int32_t(jwrap32(jwint((jshr(int32_t(jwrap32(jwint((j::__ci(),j::f_d)->f_i) - jwint(m::F_i))),16))) * jwint((j::__ci(),j::g_d)->a_i))),16))) * jwint(L_var1))),int32_t(100))) + jwint((o::__ci(),o::c_i))));
   for (int32_t L_var16 = 0; (L_var16 < L_var7); (L_var16++)) {
      {
         if ((L_var16 < 2)) {
            (o::__ci(), o::a_iii_v(jwrap32(jwint(L_var2) + jwint(m::s_Ai[L_var16])), jwrap32(jwint(L_var1) + jwint(m::t_Ai[L_var16])), ((int32_t)(L_var0[m::u_Ai[L_var16]]))));
         }
         if ((L_var16 > 2)) {
            (o::__ci(), o::a_iii_v(jwrap32(jwint(jwrap32(jwint(L_var2) + jwint(m::s_Ai[L_var16]))) - jwint((jshl(int32_t(L_var17),1)))), jwrap32(jwint(L_var1) + jwint(m::t_Ai[L_var16])), ((int32_t)(L_var0[m::u_Ai[L_var16]]))));
         }
         (o::__ci(), o::a_iii_v(jwrap32(jwint(jwrap32(jwint(L_var2) + jwint(m::s_Ai[L_var16]))) - jwint(L_var17)), jwrap32(jwint(L_var1) + jwint(m::t_Ai[L_var16])), ((int32_t)(L_var0[m::u_Ai[L_var16]]))));
      }
   }
   if ((L_var8 != (-1))) {
      m::a_iGraphics_v(L_var8, L_var9);
      L_var9->fillRect(0, jwrap32(jwint(L_var1) + jwint(m::t_Ai[0])), (o::__ci(),o::b_i), jwrap32(jwint((o::__ci(),o::c_i)) - jwint((jwrap32(jwint(L_var1) + jwint(m::t_Ai[0]))))));
   }
}
void m::a_DirectGraphics_v(JDirectGraphics L_var0) {
   int32_t L_var1 = (o::__ci(), o::c__i());
   int32_t L_var2 = (o::__ci(),o::b_i);
   int32_t L_var3 = jwrap32(jwint((o::__ci(),o::c_i)) - jwint(L_var1));
   Arr<int32_t> L_var4 = m::v_Ai;
   Arr<int32_t> L_var5 = m::w_Ai;
   (L_var4[0] = 0);
   (L_var5[0] = L_var3);
   (L_var4[1] = jwrap32(jwint(L_var2) + jwint(0)));
   (L_var5[1] = L_var3);
   (L_var4[2] = jwrap32(jwint(L_var2) + jwint(0)));
   (L_var5[2] = jwrap32(jwint(L_var3) + jwint(L_var1)));
   (L_var4[3] = 0);
   (L_var5[3] = jwrap32(jwint(L_var3) + jwint(L_var1)));
   L_var0->fillPolygon(L_var4, 0, L_var5, 0, 4, 1426063360);
}
int32_t m::a_iiiiz_i(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, bool L_var4) {
   int32_t L_var5 = 0;
   int32_t L_var7 = 1;
   int32_t L_var6 = L_var2;
   (L_var4 = ((L_var2 < 10) && L_var4));
   if ((L_var3 == 4)) {
      (L_var7 = 0);
   }
   for (int32_t L_var10 = L_var7; (L_var10 < 2); (L_var10++)) {
      {
         if ((L_var2 == 0)) {
            if ((L_var10 == 1)) {
               (o::__ci(), o::a_iiii_v(L_var0, 7, ((int32_t)(m::w_As[0])), 24));
            }
            (L_var5 += (o::__ci(), o::a_ii_i(((int32_t)(m::w_As[0])), 0)));
         } else {
            while ((L_var2 != 0)) {
               {
                  (L_var7 = jrem(int32_t(L_var2),int32_t(10)));
                  int32_t L_var9 = ((int32_t)(m::w_As[L_var7]));
                  if ((L_var10 == 1)) {
                     (o::__ci(), o::a_iiii_v(jwrap32(jwint(L_var0) - jwint(L_var5)), 7, L_var9, 24));
                  }
                  (L_var2 = (int32_t)jdiv(L_var2,10));
                  (L_var5 += (o::__ci(), o::a_ii_i(L_var9, 0)));
               }
            }
         }
         if ((L_var10 == 0)) {
            (L_var0 += L_var5);
            (L_var5 = 0);
            (L_var2 = L_var6);
         }
      }
   }
   if (L_var4) {
      (o::__ci(), o::a_iiii_v(jwrap32(jwint(L_var0) - jwint(L_var5)), 7, ((int32_t)(m::w_As[0])), 24));
      (L_var5 += (o::__ci(), o::a_ii_i(((int32_t)(m::w_As[0])), 0)));
   }
   return L_var5;
}
JString m::b_i_String(int32_t L_var0) {
   int32_t L_var1 = jdiv(int32_t(L_var0),int32_t(60));
   JString L_var3{};
   if ((((L_var0 = jrem(int32_t(L_var0),int32_t(60)))) < 10)) {
      (L_var3 = jcat(jcat(jcat(L_var1,JS(u":")),JS(u"0")),L_var0));
   } else {
      (L_var3 = jcat(jcat(L_var1,JS(u":")),L_var0));
   }
   return L_var3;
}
void m::h__v() {
   for (int32_t L_var0 = 0; (L_var0 < m::u_As.length()); (L_var0++)) {
      {
         if ((((o::__ci(), o::a_i_Image(((int32_t)(m::u_As[L_var0])))) != nullptr) && (m::a_AImage[L_var0] != nullptr))) {
            (o::__ci(), o::a_iImage_v(((int32_t)(m::u_As[L_var0])), m::a_AImage[L_var0]));
         }
      }
   }
}
void m::i__v() {
   if (m::h_z) {
      (g::__ci(), g::a_Ag_v(m::a_Ag));
      (m::h_z = false);
   } else {
      m::a_j->l__v();
      for (j* L_var0 = m::a_j; (L_var0 != nullptr); (L_var0 = L_var0->a_j_j(m::a_j))) {
         {
            L_var0->d__v();
         }
      }
      (g::__ci(), g::a_Agc_v(m::a_Ag, m::a_c));
      int32_t L_var1 = (g::__ci(),g::a_Ai)[7];
      (g::__ci(), g::a_Ag_v(m::a_Ag));
      if (((g::__ci(),g::a_Ai)[7] != L_var1)) {
         (m::l_z = false);
         (m::H_i = 2000);
         (m::I_i = 0);
      }
      for (j* L_var2 = m::a_j; (L_var2 != nullptr); (L_var2 = L_var2->a_j_j(m::a_j))) {
         {
            L_var2->a_j_v(m::a_j);
         }
      }
      if (m::c_z) {
         ((j::__ci(),j::n_i) = 0);
         ((j::__ci(),j::o_i) = 0);
         (j::__ci(), j::b_z_v(true));
         (m::c_z = false);
      } else {
         (j::__ci(), j::b_z_v(false));
      }
   }
}
void m::j__v() {
   m::h__v();
   (this->k_z = false);
   (o::__ci(), o::a_i_v(5));
   (m::A_i = 31);
   ((g::__ci(),g::a_Ai)[0] = 0);
}
void n::__clinit() {
   __inited = true;
   j::__ci();
   a_z = false;
   g_Ai = newArr<int32_t>(2);
}
n::n(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, Arr<int32_t> L_var8, int32_t L_var9, int32_t L_var10) {
   if ((!n::a_z)) {
      (n::a_z = true);
   }
   (this->a_Ai = newArr<int32_t>(L_var1));
   (this->b_Ai = newArr<int32_t>(L_var1));
   (this->c_Ai = newArr<int32_t>(L_var1));
   (this->d_Ai = newArr<int32_t>(L_var1));
   (this->e_Ai = newArr<int32_t>(L_var1));
   (this->b_Ab = newArr<int8_t>(L_var1));
   if ((L_var7 == 4)) {
      (this->a_As = newArr<int16_t>(L_var1));
      (this->a_Ab = newArr<int8_t>(L_var1));
      for (int32_t L_var11 = 0; (L_var11 < L_var1); (L_var11++)) {
         {
            (this->a_As[L_var11] = ((int16_t)(0)));
         }
      }
   }
   (this->v_i = L_var1);
   (this->d_i = 0);
   (this->r_i = L_var3);
   (this->s_i = 0);
   (this->t_i = 0);
   (this->u_i = L_var6);
   (this->a_i = (-1));
   (this->w_i = L_var7);
   (this->c_b = ((int8_t)(11)));
   (this->f_Ai = L_var8);
   (this->x_i = L_var9);
   (this->b_b = ((int8_t)(L_var10)));
}
void n::c_j_v(j* L_var1) {
   this->b_j_v(L_var1);
   (this->c_d->a_i = 65536);
   (this->c_d->b_i = 0);
   (this->c_d->c_i = 0);
   (this->c_d->d_i = 0);
   (this->c_d->e_i = 65536);
   (this->c_d->f_i = 0);
   this->b_d->a_d_v(this->c_d);
   this->a__v();
}
void n::a_iiiiiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7) {
   if ((jwrap32(jwint(jwrap32(jwint(L_var1) + jwint(1))) + jwint(this->a_i)) > this->v_i)) {
      (L_var1 = jwrap32(jwint(jwrap32(jwint(this->v_i) - jwint(this->a_i))) - jwint(1)));
   }
   (L_var2 = L_var2);
   (L_var3 = L_var3);
   for (int32_t L_var10 = 0; (L_var10 < L_var1); (L_var10++)) {
      {
         int32_t L_var8 = ((jwrap32(jwint(((L_var5 = jdiv(int32_t(jwrap32(jwint(L_var10) * jwint(360))),int32_t(L_var1))))) + jwint(90)) >= 360) ? jwrap32(jwint(jwrap32(jwint(L_var5) + jwint(90))) - jwint(360)) : jwrap32(jwint(L_var5) + jwint(90)));
         (this->a_i++);
         ([&]() -> decltype(auto) { auto& __a989 = this->a_Ai[this->a_i]; auto __v990 = ((L_var7 != 0) ? ([&]() { auto __l987 = L_var6; auto __r988 = ([&]() { auto __l985 = (m::__ci(),m::a_Random)->nextInt(); auto __r986 = L_var7; return jrem(int32_t(__l985),int32_t(__r986)); }()); return jwrap32(jwint(__l987) + jwint(__r988)); }()) : L_var6); return (__a989 = __v990); }());
         (this->b_Ai[this->a_i] = L_var2);
         (this->c_Ai[this->a_i] = L_var3);
         (this->d_Ai[this->a_i] = jwrap32(jwint(L_var4) * jwint((m::__ci(),m::b_As)[L_var5])));
         (this->e_Ai[this->a_i] = jwrap32(jwint(L_var4) * jwint((m::__ci(),m::b_As)[L_var8])));
         if ((this->w_i == 3)) {
            (this->b_Ab[this->a_i] = ((int8_t)((jrem(int32_t(L_var10),int32_t(this->f_Ai.length()))))));
         } else {
            if (((this->w_i == 4) && this->equals((m::__ci(),m::a_n)))) {
               int32_t L_var14{};
               if ((((L_var14 = ((int32_t)(((int8_t)(jmath_abs<int32_t>(([&]() { auto __l991 = (m::__ci(),m::a_Random)->nextInt(); auto __r992 = this->f_Ai.length(); return jrem(int32_t(__l991),int32_t(__r992)); }())))))))) > 1)) {
                  (L_var14 = ((int32_t)(((int8_t)(jmath_abs<int32_t>(([&]() { auto __l993 = (m::__ci(),m::a_Random)->nextInt(); auto __r994 = this->f_Ai.length(); return jrem(int32_t(__l993),int32_t(__r994)); }())))))));
               }
               (this->b_Ab[this->a_i] = ((int8_t)(L_var14)));
            } else {
               ([&]() -> decltype(auto) { auto& __a997 = this->b_Ab[this->a_i]; auto __v998 = ((int8_t)(jmath_abs<int32_t>(([&]() { auto __l995 = (m::__ci(),m::a_Random)->nextInt(); auto __r996 = this->f_Ai.length(); return jrem(int32_t(__l995),int32_t(__r996)); }())))); return (__a997 = __v998); }());
            }
         }
      }
   }
}
void n::a_iiiiiiiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, int32_t L_var8, int32_t L_var9) {
   if ((jwrap32(jwint(jwrap32(jwint(L_var1) + jwint(1))) + jwint(this->a_i)) > this->v_i)) {
      (L_var1 = jwrap32(jwint(jwrap32(jwint(this->v_i) - jwint(this->a_i))) - jwint(1)));
   }
   (L_var2 = L_var2);
   (L_var3 = L_var3);
   for (int32_t L_var13 = 0; (L_var13 < L_var1); (L_var13++)) {
      {
         int32_t L_var10{};
         int32_t L_var16{};
         int32_t L_var17{};
         int32_t L_var11 = ((jwrap32(jwint(((L_var17 = ([&]() { auto __l1005 = ((L_var16 = ([&]() { auto __l1003 = ((L_var10 = ([&]() { auto __l1001 = L_var6; auto __r1002 = ([&]() { auto __l999 = (m::__ci(),m::a_Random)->nextInt(); auto __r1000 = (jwrap32(jwint(jdiv(int32_t(L_var7),int32_t(2))) + jwint(1))); return jrem(int32_t(__l999),int32_t(__r1000)); }()); return jwrap32(jwint(__l1001) + jwint(__r1002)); }()))); auto __r1004 = (((L_var10 >= 360) ? 360 : 0)); return jwrap32(jwint(__l1003) - jwint(__r1004)); }()))); auto __r1006 = (((L_var16 < 0) ? 360 : 0)); return jwrap32(jwint(__l1005) + jwint(__r1006)); }())))) + jwint(90)) >= 360) ? jwrap32(jwint(L_var17) - jwint(270)) : jwrap32(jwint(L_var17) + jwint(90)));
         int32_t L_var12 = ((L_var5 != 0) ? ([&]() { auto __l1009 = L_var4; auto __r1010 = ([&]() { auto __l1007 = (m::__ci(),m::a_Random)->nextInt(); auto __r1008 = L_var5; return jrem(int32_t(__l1007),int32_t(__r1008)); }()); return jwrap32(jwint(__l1009) + jwint(__r1010)); }()) : L_var4);
         (this->a_i++);
         ([&]() -> decltype(auto) { auto& __a1015 = this->a_Ai[this->a_i]; auto __v1016 = ((L_var9 != 0) ? ([&]() { auto __l1013 = L_var8; auto __r1014 = ([&]() { auto __l1011 = (m::__ci(),m::a_Random)->nextInt(); auto __r1012 = L_var9; return jrem(int32_t(__l1011),int32_t(__r1012)); }()); return jwrap32(jwint(__l1013) + jwint(__r1014)); }()) : L_var8); return (__a1015 = __v1016); }());
         (this->b_Ai[this->a_i] = L_var2);
         (this->c_Ai[this->a_i] = L_var3);
         (this->d_Ai[this->a_i] = jwrap32(jwint(L_var12) * jwint((m::__ci(),m::b_As)[L_var17])));
         (this->e_Ai[this->a_i] = jwrap32(jwint(L_var12) * jwint((m::__ci(),m::b_As)[L_var11])));
         if ((this->w_i == 0)) {
            if (((L_var17 >= 35) && (L_var17 <= 90))) {
               (this->b_Ab[this->a_i] = ((int8_t)(2)));
            } else {
               if ((L_var17 < 35)) {
                  (this->b_Ab[this->a_i] = ((int8_t)(3)));
               } else {
                  if ((L_var17 > 325)) {
                     (this->b_Ab[this->a_i] = ((int8_t)(1)));
                  } else {
                     (this->b_Ab[this->a_i] = ((int8_t)(0)));
                  }
               }
            }
         } else {
            if ((this->w_i == 7)) {
               if (((L_var6 != 0) && (L_var6 != 180))) {
                  (this->b_Ab[this->a_i] = ((int8_t)(1)));
               } else {
                  (this->b_Ab[this->a_i] = ((int8_t)(0)));
               }
            } else {
               ([&]() -> decltype(auto) { auto& __a1019 = this->b_Ab[this->a_i]; auto __v1020 = ((int8_t)(jmath_abs<int32_t>(([&]() { auto __l1017 = (m::__ci(),m::a_Random)->nextInt(); auto __r1018 = this->f_Ai.length(); return jrem(int32_t(__l1017),int32_t(__r1018)); }())))); return (__a1019 = __v1020); }());
            }
         }
      }
   }
}
void n::a_iiiiiiiiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, int32_t L_var8, int32_t L_var9, int32_t L_var10) {
   if ((jwrap32(jwint(11) + jwint(this->a_i)) > this->v_i)) {
      (L_var1 = jwrap32(jwint(jwrap32(jwint(this->v_i) - jwint(this->a_i))) - jwint(1)));
   }
   (L_var2 = L_var2);
   (L_var3 = L_var3);
   for (int32_t L_var16 = 0; (L_var16 < L_var1); (L_var16++)) {
      {
         (L_var4 = jwrap32(jwint(800) + jwint(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(200)))));
         (this->a_i++);
         ([&]() -> decltype(auto) { auto& __a1021 = this->a_Ai[this->a_i]; auto __v1022 = jwrap32(jwint(800) + jwint(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(200)))); return (__a1021 = __v1022); }());
         (this->b_Ai[this->a_i] = L_var2);
         (this->c_Ai[this->a_i] = L_var3);
         (L_var5 = ([&]() { auto __l1023 = L_var6; auto __r1024 = (jshl(int32_t(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(30))),10)); return jwrap32(jwint(__l1023) + jwint(__r1024)); }()));
         (L_var8 = ([&]() { auto __l1025 = L_var7; auto __r1026 = (jshl(int32_t(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(30))),10)); return jwrap32(jwint(__l1025) + jwint(__r1026)); }()));
         (this->d_Ai[this->a_i] = jshr(int32_t(jwrap32(jwint(L_var4) * jwint(L_var5))),8));
         (this->e_Ai[this->a_i] = jshr(int32_t(jwrap32(jwint(L_var4) * jwint(L_var8))),8));
         ([&]() -> decltype(auto) { auto& __a1029 = this->b_Ab[this->a_i]; auto __v1030 = ((int8_t)(jmath_abs<int32_t>(([&]() { auto __l1027 = (m::__ci(),m::a_Random)->nextInt(); auto __r1028 = this->f_Ai.length(); return jrem(int32_t(__l1027),int32_t(__r1028)); }())))); return (__a1029 = __v1030); }());
      }
   }
}
void n::b_iiiiiiiiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, int32_t L_var8, int32_t L_var9, int32_t L_var10) {
   for (int32_t L_var15 = 0; (L_var15 < L_var1); (L_var15++)) {
      {
         do {
            {
               (L_var5 = ([&]() { auto __l1031 = (m::__ci(),m::a_Random)->nextInt(); auto __r1032 = (jwrap32(jwint(jwrap32(jwint(L_var4) * jwint(2))) + jwint(1))); return jrem(int32_t(__l1031),int32_t(__r1032)); }()));
               (L_var6 = ([&]() { auto __l1033 = (m::__ci(),m::a_Random)->nextInt(); auto __r1034 = (jwrap32(jwint(jwrap32(jwint(L_var4) * jwint(2))) + jwint(1))); return jrem(int32_t(__l1033),int32_t(__r1034)); }()));
            }
         } while ((jwrap32(jwint(jwrap32(jwint(L_var5) * jwint(L_var5))) + jwint(jwrap32(jwint(L_var6) * jwint(L_var6)))) > jwrap32(jwint(L_var4) * jwint(L_var4))));
         (L_var5 = jwrap32(jwint(L_var2) + jwint(L_var5)));
         (L_var6 = jwrap32(jwint(L_var3) + jwint(L_var6)));
         this->a_iiiiiiiii_v(1, L_var5, L_var6, 0, 0, 0, 0, L_var9, L_var10);
      }
   }
}
void n::a_iiiiiiiiiii_v(int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5, int32_t L_var6, int32_t L_var7, int32_t L_var8, int32_t L_var9, int32_t L_var10, int32_t L_var11) {
   for (int32_t L_var14 = 0; (L_var14 < L_var1); (L_var14++)) {
      {
         int32_t L_var12 = ([&]() { auto __l1037 = L_var2; auto __r1038 = jmath_abs<int32_t>(([&]() { auto __l1035 = (m::__ci(),m::a_Random)->nextInt(); auto __r1036 = (jwrap32(jwint(jwrap32(jwint(L_var4) - jwint(L_var2))) + jwint(1))); return jrem(int32_t(__l1035),int32_t(__r1036)); }())); return jwrap32(jwint(__l1037) + jwint(__r1038)); }());
         int32_t L_var13 = ([&]() { auto __l1041 = L_var3; auto __r1042 = jmath_abs<int32_t>(([&]() { auto __l1039 = (m::__ci(),m::a_Random)->nextInt(); auto __r1040 = (jwrap32(jwint(jwrap32(jwint(L_var5) - jwint(L_var3))) + jwint(1))); return jrem(int32_t(__l1039),int32_t(__r1040)); }())); return jwrap32(jwint(__l1041) + jwint(__r1042)); }());
         this->a_iiiiiiiii_v(1, L_var12, L_var13, L_var6, L_var7, L_var8, L_var9, L_var10, L_var11);
      }
   }
}
void n::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   int32_t L_var7 = ([&]() { auto __l1043 = (o::__ci(),o::a_i); auto __r1044 = (o::__ci(), o::a__i()); return jwrap32(jwint(__l1043) * jwint(__r1044)); }());
   for (int32_t L_var4 = 0; (L_var4 < jwrap32(jwint(this->a_i) + jwint(1))); (L_var4++)) {
      {
         bool L_var8 = false;
         (this->a_Ai[L_var4] = jwrap32(jwint(this->a_Ai[L_var4]) - jwint(L_var7)));
         if ((this->a_Ai[L_var4] > 0)) {
            if ((this->u_i != 0)) {
               (this->d_Ai[L_var4] = jwrap32(jwint(this->d_Ai[L_var4]) - jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(this->d_Ai[L_var4]) * jwint(this->u_i))) * jwint(L_var7))),14)))));
               (this->e_Ai[L_var4] = jwrap32(jwint(this->e_Ai[L_var4]) - jwint((jshr(int32_t(jwrap32(jwint(jwrap32(jwint(this->e_Ai[L_var4]) * jwint(this->u_i))) * jwint(L_var7))),14)))));
            }
            (this->d_Ai[L_var4] = jwrap32(jwint(this->d_Ai[L_var4]) + jwint(jwrap32(jwint(this->d_i) * jwint(L_var7)))));
            (this->e_Ai[L_var4] = jwrap32(jwint(this->e_Ai[L_var4]) + jwint(jwrap32(jwint(this->r_i) * jwint(L_var7)))));
            if (((this->w_i == 1) && (this->e_Ai[L_var4] > this->c_i))) {
               (this->e_Ai[L_var4] = this->c_i);
            } else {
               if ((this->w_i == 4)) {
                  (this->a_As[L_var4] = ((int16_t)((jwrap32(jwint(this->a_As[L_var4]) - jwint(L_var7))))));
                  if ((this->a_As[L_var4] <= 0)) {
                     ([&]() -> decltype(auto) { auto& __a1045 = this->a_As[L_var4]; auto __v1046 = ((int16_t)((jwrap32(jwint(jmath_abs<int32_t>(jrem(int32_t((m::__ci(),m::a_Random)->nextInt()),int32_t(200)))) + jwint(300))))); return (__a1045 = __v1046); }());
                     ([&]() -> decltype(auto) { auto& __a1047 = this->a_Ab[L_var4]; auto __v1048 = ((int8_t)(((jmath_abs<int32_t>((m::__ci(),m::a_Random)->nextInt()) & 3)))); return (__a1047 = __v1048); }());
                  }
                  int32_t L_var5 = jdiv(int32_t(L_var7),int32_t(2));
                  if ((this->a_Ab[L_var4] == 1)) {
                     n::a_iii_v(L_var5, this->d_Ai[L_var4], this->e_Ai[L_var4]);
                     (this->d_Ai[L_var4] = n::g_Ai[0]);
                     (this->e_Ai[L_var4] = n::g_Ai[1]);
                  } else {
                     if ((this->a_Ab[L_var4] == 2)) {
                        n::a_iii_v(jwrap32(jwint(359) - jwint(L_var5)), this->d_Ai[L_var4], this->e_Ai[L_var4]);
                        (this->d_Ai[L_var4] = n::g_Ai[0]);
                        (this->e_Ai[L_var4] = n::g_Ai[1]);
                     }
                  }
               } else {
                  if ((this->w_i == 5)) {
                     int32_t L_var11{};
                     ([&]() -> decltype(auto) { auto __p1049 = (L_var11 = jdiv(int32_t(L_var7),int32_t(5))); auto __p1050 = this->d_Ai[L_var4]; auto __p1051 = this->e_Ai[L_var4]; return n::a_iii_v(__p1049, __p1050, __p1051); }());
                     (this->d_Ai[L_var4] = n::g_Ai[0]);
                     (this->e_Ai[L_var4] = n::g_Ai[1]);
                  }
               }
            }
            (this->b_Ai[L_var4] = jwrap32(jwint(this->b_Ai[L_var4]) + jwint((jshr(int32_t(jwrap32(jwint((jwrap32(jwint(this->d_Ai[L_var4]) + jwint(this->s_i)))) * jwint(L_var7))),4)))));
            (this->c_Ai[L_var4] = jwrap32(jwint(this->c_Ai[L_var4]) + jwint((jshr(int32_t(jwrap32(jwint((jwrap32(jwint(this->e_Ai[L_var4]) + jwint(this->t_i)))) * jwint(L_var7))),4)))));
         } else {
            (L_var8 = true);
         }
         if (((this->w_i == 1) && (this->c_Ai[L_var4] >= this->b_i))) {
            (L_var8 = true);
         }
         if (L_var8) {
            if ((L_var4 == this->a_i)) {
               (this->a_i--);
            } else {
               (this->a_Ai[L_var4] = this->a_Ai[this->a_i]);
               (this->b_Ai[L_var4] = this->b_Ai[this->a_i]);
               (this->c_Ai[L_var4] = this->c_Ai[this->a_i]);
               (this->d_Ai[L_var4] = this->d_Ai[this->a_i]);
               (this->e_Ai[L_var4] = this->e_Ai[this->a_i]);
               (this->a_i--);
               (L_var4--);
            }
         } else {
            int32_t L_var12 = (o::__ci(), o::b_i_i(this->f_Ai[this->b_Ab[L_var4]]));
            int32_t L_var9{};
            if (([&]() { auto __l1052 = ((L_var9 = jdiv(int32_t(jwrap32(jwint(this->a_Ai[L_var4]) * jwint(L_var12))),int32_t(this->x_i)))); auto __r1053 = jwrap32(jwint(L_var12) - jwint(1)); return (__l1052 > __r1053); }())) {
               (L_var9 = jwrap32(jwint(L_var12) - jwint(1)));
            }
            int32_t L_var10 = jwrap32(jwint(jwrap32(jwint(L_var12) - jwint(1))) - jwint(L_var9));
            L_var3->a_ii_v(this->b_Ai[L_var4], this->c_Ai[L_var4]);
            (L_var12 = jshr(int32_t((d::__ci(),d::g_i)),16));
            int32_t L_var6 = jshr(int32_t((d::__ci(),d::h_i)),16);
            (o::__ci(), o::b_iiii_v(L_var12, L_var6, this->f_Ai[this->b_Ab[L_var4]], L_var10));
         }
      }
   }
}
void n::a_iii_v(int32_t L_var0, int32_t L_var1, int32_t L_var2) {
   int32_t L_var3 = ((int32_t)((m::__ci(),m::b_As)[jrem(int32_t(L_var0),int32_t(360))]));
   int32_t L_var4 = ((int32_t)((m::__ci(),m::b_As)[jrem(int32_t((jwrap32(jwint(L_var0) + jwint(90)))),int32_t(360))]));
   (n::g_Ai[0] = jdiv(int32_t((jwrap32(jwint(jwrap32(jwint(L_var1) * jwint(L_var4))) - jwint(jwrap32(jwint(L_var2) * jwint(L_var3)))))),int32_t(360)));
   (n::g_Ai[1] = jdiv(int32_t((jwrap32(jwint(jwrap32(jwint(L_var1) * jwint(L_var3))) + jwint(jwrap32(jwint(L_var2) * jwint(L_var4)))))),int32_t(360)));
}
void o::__clinit() {
   __inited = true;
   a_o = nullptr;
   a_z = false;
   b_z = true;
   c_z = false;
   d_i = 500;
   a_Object = JObject::make();
   b_Object = JObject::make();
   d_z = false;
   e_z = false;
   f_z = false;
   g_z = false;
   g_i = (-1);
   h_z = false;
   h_i = 500;
   i_i = 1;
   j_i = 0;
   a_Ac = Arr<char16_t>({char16_t(u'\n'), char16_t(u' '), char16_t(u'-')});
   b_i = 240;
   c_i = 320;
   a_Graphics = nullptr;
   b_Graphics = nullptr;
   a_AFont = Arr<JFont>({JFontImpl::getFont(64, 2, 0), JFontImpl::getFont(64, 1, 0), JFontImpl::getFont(64, 0, 0)});
   d_Ai = newArr<int32_t>(2);
   k_i = 0;
   m_i = (-1);
   b_As = newArr<int16_t>(6);
   n_i = (-1);
   p_i = 0;
   i_z = false;
   j_z = false;
   a_Player = nullptr;
   b_Player = nullptr;
   q_i = 60;
   r_i = (-1);
   s_i = 1;
   t_i = 0;
   u_i = 0;
   v_i = 0;
   c_l = (int64_t)0LL;
   x_i = 0;
   y_i = 0;
   d_l = (int64_t)0LL;
   l_z = false;
   a_AAc = Arr<Arr<char16_t>>({Arr<char16_t>({char16_t(u' '), char16_t(u'0')}), Arr<char16_t>({char16_t(u'.'), char16_t(u','), char16_t(u'?'), char16_t(u'!'), char16_t(u'\''), char16_t(u'-'), char16_t(u'('), char16_t(u')'), char16_t(u'@'), char16_t(u'/'), char16_t(u':'), char16_t(u'_'), char16_t(u'1')}), Arr<char16_t>({char16_t(u'a'), char16_t(u'b'), char16_t(u'c'), char16_t(u'ä'), char16_t(u'å'), char16_t(u'2')}), Arr<char16_t>({char16_t(u'd'), char16_t(u'e'), char16_t(u'f'), char16_t(u'3')}), Arr<char16_t>({char16_t(u'g'), char16_t(u'h'), char16_t(u'i'), char16_t(u'4')}), Arr<char16_t>({char16_t(u'j'), char16_t(u'k'), char16_t(u'l'), char16_t(u'5')}), Arr<char16_t>({char16_t(u'm'), char16_t(u'n'), char16_t(u'o'), char16_t(u'ö'), char16_t(u'6')}), Arr<char16_t>({char16_t(u'p'), char16_t(u'q'), char16_t(u'r'), char16_t(u's'), char16_t(u'7')}), Arr<char16_t>({char16_t(u't'), char16_t(u'u'), char16_t(u'v'), char16_t(u'8')}), Arr<char16_t>({char16_t(u'w'), char16_t(u'x'), char16_t(u'y'), char16_t(u'z'), char16_t(u'9')}), newArr<char16_t>(0), newArr<char16_t>(0)});
   b_AAc = nullptr;
   m_z = false;
}
o::o() : JGameCanvasBase(false) {
}
void o::i_i_v(int32_t L_var0) {
   if ((o::e_i != 20)) {
      (o::a_Ai[o::e_i] = L_var0);
      (o::e_i++);
   }
}
void o::a_i_v(int32_t L_var0) {
   if ((o::f_i == 40)) {
      jthrow(JRuntimeException::make());
   } else {
      (o::b_Ai[o::f_i] = L_var0);
      (o::f_i++);
   }
}
void o::a__v() {
   (o::g_z = true);
}
void o::b_i_v(int32_t L_var0) {
   (o::i_i = 2);
}
int32_t o::a__i() {
   return o::i_i;
}
void o::c_i_v(int32_t L_var0) {
   (o::h_i = L_var0);
}
void o::a_iStringi_v(int32_t L_var0, JString L_var1, int32_t L_var2) {
   (o::a_AString[L_var0] = L_var1);
   (o::c_Ai[L_var0] = L_var2);
}
void o::b__v() {
   for (int32_t L_var0 = 0; (L_var0 < 3); (L_var0++)) {
      {
         o::a_iStringi_v(L_var0, nullptr, (-1));
      }
   }
}
int32_t o::b__i() {
   if (([&]() { auto __l1054 = ((o::c_i_i(0) & 114)); auto __r1055 = ((o::c_i_i(1) & 114)); return (__l1054 == __r1055); }())) {
      return ((((o::c_i_i(0) & 32)) == 32) ? 2 : 1);
   } else {
      if (([&]() { auto __l1056 = ((o::c_i_i(0) & 13)); auto __r1057 = ((o::c_i_i(1) & 13)); return (__l1056 == __r1057); }())) {
         return ((((o::c_i_i(0) & 4)) == 4) ? 3 : 4);
      } else {
         return 0;
      }
   }
}
int32_t o::c__i() {
   return ((o::b__i() != 0) ? (m::__ci(), m::b__i()) : 0);
}
int32_t o::d__i() {
   return ((o::b__i() != 0) ? (-1) : 0);
}
int32_t o::c_i_i(int32_t L_var0) {
   {
      switch (L_var0) {
      case 0:
      {
         return 33;
      }
      case 1:
      {
         return 40;
      }
      case 2:
      {
         return 36;
      }
      default:
      {
         return (-1);
      }
      }
   }
}
bool o::a__z() {
   return ((o::b__i() == 3) || (o::b__i() == 4));
}
bool o::b__z() {
   return ((o::b__i() == 1) || (o::b__i() == 2));
}
Arr<JString> o::a_Stringiiziiz_AString(JString L_var0, int32_t L_var1, int32_t L_var2, bool L_var3, int32_t L_var4, int32_t L_var5, bool L_var6) {
   Arr<JString> L_var7 = newArr<JString>(5);
   int32_t L_var8 = 0;
   int32_t L_var9 = 0;
   int32_t L_var10 = 0;
   int32_t L_var11 = 0;
   int32_t L_var12 = L_var4;
   (L_var8 = 0);
   (L_var9 = L_var0.length());
   int32_t L_var13 = 0;
   while ((L_var13 < L_var9)) {
      {
         bool L_var14{};
         int32_t L_var15{};
         if ((L_var14 = (L_var3 && ([&]() { auto __l1060 = ([&]() { auto __l1058 = o::a_i_i(L_var2); auto __r1059 = L_var10; return jwrap32(jwint(__l1058) * jwint(__r1059)); }()); auto __r1061 = L_var5; return (__l1060 < __r1061); }())))) {
            (L_var15 = jwrap32(jwint(L_var1) - jwint(L_var4)));
            (L_var11++);
         } else {
            (L_var15 = L_var1);
         }
         int32_t L_var16 = 0;
         int32_t L_var17 = L_var13;
         int32_t L_var18 = L_var9;
         while ((L_var13 < L_var9)) {
            {
               int32_t L_var19 = L_var9;
               for (int32_t L_var20 = L_var13; (L_var20 < L_var9); (L_var20++)) {
                  {
                     int32_t L_var21 = 0;
                     while (((L_var21 < o::a_Ac.length()) && ([&]() { auto __l1062 = L_var0.charAt(L_var20); auto __r1063 = o::a_Ac[L_var21]; return (__l1062 != __r1063); }()))) {
                        {
                           (L_var21++);
                        }
                     }
                     if ((L_var21 < o::a_Ac.length())) {
                        (L_var19 = L_var20);
                        if ((L_var0.charAt(L_var20) == char16_t(u'-'))) {
                           (L_var19 = jwrap32(jwint(L_var20) + jwint(1)));
                        }
                        break;
                     }
                  }
               }
               if (([&]() { auto __l1064 = o::a_iStringii_i(L_var2, L_var0, L_var17, jwrap32(jwint(L_var19) - jwint(L_var17))); auto __r1065 = L_var15; return (__l1064 >= __r1065); }())) {
                  if ((L_var16 != 0)) {
                     break;
                  }
                  int32_t L_var33 = L_var17;
                  while (([&]() { auto __l1066 = o::a_iStringii_i(L_var2, L_var0, L_var17, jwrap32(jwint(jwrap32(jwint(L_var33) - jwint(L_var17))) + jwint(1))); auto __r1067 = L_var15; return (__l1066 < __r1067); }())) {
                     {
                        (L_var33++);
                     }
                  }
                  (L_var18 = L_var33);
                  (L_var13 = L_var33);
                  break;
               }
               (L_var18 = L_var19);
               (L_var13 = L_var19);
               (L_var16++);
               if (((L_var19 < L_var9) && (L_var0.charAt(L_var19) == char16_t(u'\n')))) {
                  break;
               }
               while ((L_var13 < L_var9)) {
                  {
                     int32_t L_var32 = 0;
                     while (((L_var32 < o::a_Ac.length()) && ([&]() { auto __l1068 = L_var0.charAt(L_var13); auto __r1069 = o::a_Ac[L_var32]; return (__l1068 != __r1069); }()))) {
                        {
                           (L_var32++);
                        }
                     }
                     if ((((L_var32 >= o::a_Ac.length()) || (L_var0.charAt(L_var13) == char16_t(u'-'))) || (L_var0.charAt(L_var13) == char16_t(u'\n')))) {
                        break;
                     }
                     (L_var13++);
                  }
               }
            }
         }
         int32_t L_var31 = o::a_iStringii_i(L_var2, L_var0, L_var17, jwrap32(jwint(L_var18) - jwint(L_var17)));
         if (L_var14) {
            (L_var12 = jmath_max<int32_t>(L_var12, jwrap32(jwint(L_var31) + jwint(L_var4))));
            (L_var8 = jmath_max<int32_t>(L_var8, jwrap32(jwint(L_var31) + jwint(L_var4))));
         } else {
            (L_var8 = jmath_max<int32_t>(L_var8, L_var31));
         }
         int32_t L_var10001 = jwrap32(jwint(L_var10) + jwint(1));
         JString L_var29 = L_var0.substring(L_var17, L_var18);
         int32_t L_var14i = L_var10001;
         if ((L_var7.length() <= L_var14i)) {
            Arr<JString> L_var30 = newArr<JString>(jwrap32(jwint(L_var7.length()) + jwint(5)));
            JSystem::arraycopy(L_var7, 0, L_var30, 0, L_var7.length());
            (L_var7 = L_var30);
         }
         (L_var7[L_var14i] = L_var29);
         (L_var10++);
         if (((L_var13 < L_var9) && (L_var0.charAt(L_var13) == char16_t(u'\n')))) {
            (L_var13++);
         }
         try {
            JThread::sleep((int64_t)1LL);
         }
         catch (JInterruptedException& L_var22) {
         }
      }
   }
   if (L_var6) {
      (L_var8 = L_var8);
   } else {
      (L_var8 = L_var1);
   }
   if (L_var3) {
      (L_var9 = ([&]() -> decltype(auto) { auto __p1072 = ([&]() { auto __l1070 = L_var10; auto __r1071 = o::a_i_i(L_var2); return jwrap32(jwint(__l1070) * jwint(__r1071)); }()); auto __p1073 = L_var5; return jmath_max<int32_t>(__p1072, __p1073); }()));
   } else {
      (L_var9 = ([&]() { auto __l1076 = ([&]() { auto __l1074 = L_var10; auto __r1075 = o::a_i_i(L_var2); return jwrap32(jwint(__l1074) * jwint(__r1075)); }()); auto __r1077 = L_var5; return jwrap32(jwint(__l1076) + jwint(__r1077)); }()));
   }
   (L_var7[0] = jcat(jcat(jcat(jcat(jcat(jcat(jcat(jcat(jcat(JS(u""),L_var10),JS(u" ")),L_var11),JS(u" ")),L_var12),JS(u" ")),L_var8),JS(u" ")),L_var9));
   return L_var7;
}
int32_t o::e__i() {
   return o::b_i;
}
bool o::a_i_z(int32_t L_var0) {
   return (((o::v_i & jshl(int32_t(1),L_var0))) != 0);
}
void o::d_i_v(int32_t L_var0) {
   (o::t_i = 0);
   (o::s_i = 2);
}
void o::c__v() {
   (o::t_i = 0);
   (o::v_i = 0);
   (o::u_i = 0);
   (o::w_i = 0);
   (o::k_z = true);
}
void o::a_StringAb_v(JString L_var0, Arr<int8_t> L_var1) {
   JRecordStore L_var2 = nullptr;
   {
      auto __fin34960 = jfinally([&]() {
         try {
            if ((L_var2 != nullptr)) {
               L_var2->closeRecordStore();
            }
         }
         catch (JException& L_var10) {
         }
      });
      try {
         if ((((L_var2 = JRecordStore::openRecordStore(L_var0, true)))->getNumRecords() < 1)) {
            L_var2->addRecord(nullptr, 0, 0);
         }
         Arr<int8_t> L_var14{};
         ([&]() -> decltype(auto) { auto& __a1078 = ((L_var14 = newArr<int8_t>(jwrap32(jwint(L_var1.length()) + jwint(2)))))[0]; auto __v1079 = 1; return (__a1078 = ((int8_t)(__v1079))); }());
         (L_var14[1] = ((int8_t)(5)));
         JSystem::arraycopy(L_var1, 0, L_var14, 2, L_var1.length());
         L_var2->setRecord(1, L_var14, 0, L_var14.length());
         return;
      }
      catch (JRecordStoreException& L_var11) {
         return;
      }
      catch (JException& L_var12) {
      }
   }
}
Arr<int8_t> o::a_String_Ab(JString L_var0) {
   JRecordStore L_var1 = nullptr;
   Arr<int8_t> L_var17{};
   {
      auto __fin67792 = jfinally([&]() {
         try {
            if ((L_var1 != nullptr)) {
               L_var1->closeRecordStore();
            }
         }
         catch (JException& L_var12) {
         }
      });
      try {
         if (((((L_var1 = JRecordStore::openRecordStore(L_var0, false))) == nullptr) || (L_var1->getNumRecords() < 1))) {
            Obj L_var18 = nullptr;
            return static_cast<Arr<int8_t>>(nullptr);
         }
         Arr<int8_t> L_var16{};
         if (((((((L_var16 = L_var1->getRecord(1))) == nullptr) || (L_var16.length() < 2)) || (L_var16[0] != 1)) || (L_var16[1] != 5))) {
            Obj L_var19 = nullptr;
            return static_cast<Arr<int8_t>>(nullptr);
         }
         Arr<int8_t> L_var2 = newArr<int8_t>(jwrap32(jwint(L_var16.length()) - jwint(2)));
         JSystem::arraycopy(L_var16, 2, L_var2, 0, L_var2.length());
         (L_var17 = L_var2);
      }
      catch (JRecordStoreException& L_var13) {
         return static_cast<Arr<int8_t>>(nullptr);
      }
      catch (JException& L_var14) {
         return static_cast<Arr<int8_t>>(nullptr);
      }
   }
   return L_var17;
}
JGraphics o::a__Graphics() {
   return o::b_Graphics;
}
void o::a_Graphics_v(JGraphics L_var0) {
   (o::b_Graphics = ((L_var0 != nullptr) ? L_var0 : o::a_Graphics));
}
bool o::a_iiiiAi_z(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, Arr<int32_t> L_var4) {
   int32_t L_var5 = o::b_Graphics->getClipX();
   int32_t L_var6 = o::b_Graphics->getClipY();
   int32_t L_var7 = o::b_Graphics->getClipWidth();
   int32_t L_var8 = o::b_Graphics->getClipHeight();
   (L_var4[0] = L_var5);
   (L_var4[1] = L_var6);
   (L_var4[2] = L_var7);
   (L_var4[3] = L_var8);
   if ((L_var0 < L_var5)) {
      (L_var2 -= jwrap32(jwint(L_var5) - jwint(L_var0)));
      (L_var0 = L_var5);
   }
   if ((L_var1 < L_var6)) {
      (L_var3 -= jwrap32(jwint(L_var6) - jwint(L_var1)));
      (L_var1 = L_var6);
   }
   if ((jwrap32(jwint(L_var0) + jwint(L_var2)) > jwrap32(jwint(L_var5) + jwint(L_var7)))) {
      (L_var2 = jwrap32(jwint(jwrap32(jwint(L_var5) + jwint(L_var7))) - jwint(L_var0)));
   }
   if ((jwrap32(jwint(L_var1) + jwint(L_var3)) > jwrap32(jwint(L_var6) + jwint(L_var8)))) {
      (L_var3 = jwrap32(jwint(jwrap32(jwint(L_var6) + jwint(L_var8))) - jwint(L_var1)));
   }
   if (((L_var2 > 0) && (L_var3 > 0))) {
      o::b_Graphics->setClip(L_var0, L_var1, L_var2, L_var3);
      return true;
   } else {
      return false;
   }
}
int32_t o::a_iStringii_i(int32_t L_var0, JString L_var1, int32_t L_var2, int32_t L_var3) {
   int32_t L_var4{};
   if ((L_var0 == (-1))) {
      (L_var4 = 0);
   } else {
      if ((L_var0 == (-2))) {
         (L_var4 = 1);
      } else {
         if ((L_var0 != (-3))) {
            return (-1);
         }
         (L_var4 = 2);
      }
   }
   return o::a_AFont[L_var4]->substringWidth(L_var1, L_var2, L_var3);
}
int32_t o::a_i_i(int32_t L_var0) {
   int32_t L_var1{};
   if ((L_var0 == (-1))) {
      (L_var1 = 0);
   } else {
      if ((L_var0 == (-2))) {
         (L_var1 = 1);
      } else {
         if ((L_var0 != (-3))) {
            return (-1);
         }
         (L_var1 = 2);
      }
   }
   return o::a_AFont[L_var1]->getHeight();
}
void o::a_ii_v(int32_t L_var0, int32_t L_var1) {
   (o::m_i = L_var0);
   (o::l_i = L_var1);
   (o::d_Ai[0] = 0);
}
int32_t o::f__i() {
   return o::m_i;
}
void o::b_ii_v(int32_t L_var0, int32_t L_var1) {
   (o::d_Ai[L_var0] = L_var1);
}
void o::a_Stringiiiii_v(JString L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4, int32_t L_var5) {
   int32_t L_var6{};
   if ((o::m_i == (-1))) {
      (L_var6 = 0);
   } else {
      if ((o::m_i == (-2))) {
         (L_var6 = 1);
      } else {
         if ((o::m_i != (-3))) {
            return;
         }
         (L_var6 = 2);
      }
   }
   if ((((L_var5 & 2)) == 2)) {
      (L_var5 = ((L_var5 & (-3)) | 16));
      (L_var4 -= jdiv(int32_t(o::a_i_i(o::m_i)),int32_t(2)));
   }
   o::b_Graphics->setFont(o::a_AFont[L_var6]);
   if ((o::l_i != 1)) {
      o::b_Graphics->setColor(o::d_Ai[1]);
      {
         switch (o::l_i) {
         case 2:
         {
            o::b_Graphics->drawSubstring(L_var0, 0, L_var2, jwrap32(jwint(L_var3) + jwint(1)), jwrap32(jwint(L_var4) + jwint(1)), L_var5);
            break;
         }
         case 3:
         {
            (L_var6 = 0);
            while ((L_var6 < 4)) {
               {
                  ([&]() -> decltype(auto) { auto __p1084 = L_var0; auto __p1085 = 0; auto __p1086 = L_var2; auto __p1087 = jwrap32(jwint(L_var3) + jwint(jwrap32(jwint(((L_var6 & 1))) * jwint((jwrap32(jwint(L_var6) - jwint(2))))))); auto __p1088 = ([&]() { auto __l1082 = L_var4; auto __r1083 = ([&]() { auto __l1080 = (((++L_var6) & 1)); auto __r1081 = (jwrap32(jwint(L_var6) - jwint(2))); return jwrap32(jwint(__l1080) * jwint(__r1081)); }()); return jwrap32(jwint(__l1082) + jwint(__r1083)); }()); auto __p1089 = L_var5; return o::b_Graphics->drawSubstring(__p1084, __p1085, __p1086, __p1087, __p1088, __p1089); }());
               }
            }
         }
         }
      }
   }
   o::b_Graphics->setColor(o::d_Ai[0]);
   o::b_Graphics->drawSubstring(L_var0, 0, L_var2, L_var3, L_var4, L_var5);
}
void o::e_i_v(int32_t L_var0) {
   if ((L_var0 >= 0)) {
      JInteger L_var1 = JInteger::make(L_var0);
      if ((!o::a_Vector->contains(L_var1))) {
         o::a_Vector->addElement(L_var1);
      }
      o::b_Vector->removeElement(L_var1);
   }
}
void o::f_i_v(int32_t L_var0) {
   if ((L_var0 >= 0)) {
      JInteger L_var1 = JInteger::make(L_var0);
      if ((!o::b_Vector->contains(L_var1))) {
         o::b_Vector->addElement(L_var1);
      }
      o::a_Vector->removeElement(L_var1);
   }
}
Obj o::a_i_Object(int32_t L_var0) {
   if ((L_var0 < 0)) {
      return static_cast<Obj>(nullptr);
   } else {
      return ((o::a_AObject != nullptr) ? o::a_AObject[L_var0] : static_cast<Obj>(nullptr));
   }
}
bool o::b_i_z(int32_t L_var0) {
   return ((L_var0 < 0) ? false : ((o::a_Az != nullptr) && o::a_Az[L_var0]));
}
void o::a_DataInputStreami_v(JDataInputStream L_var0, int32_t L_var1) {
   int32_t L_var2 = 0;
   while ((L_var2 < L_var1)) {
      {
         (L_var2 = L_var0->skipBytes(jwrap32(jwint(L_var1) - jwint(L_var2))));
      }
   }
}
Arr<int8_t> o::a_InputStreami_Ab(JInputStream L_var0, int32_t L_var1) {
   if ((L_var1 != (-1))) {
      Arr<int8_t> L_var5 = newArr<int8_t>(L_var1);
      int32_t L_var6 = 0;
      while ((L_var6 < L_var5.length())) {
         {
            (L_var6 += L_var0->read(L_var5, L_var6, jwrap32(jwint(L_var5.length()) - jwint(L_var6))));
         }
      }
      return L_var5;
   } else {
      JByteArrayOutputStream L_var4 = JByteArrayOutputStream::make();
      Arr<int8_t> L_var2 = newArr<int8_t>(1024);
      int32_t L_var3{};
      while ((((L_var3 = L_var0->read(L_var2))) >= 0)) {
         {
            L_var4->write(L_var2, 0, L_var3);
         }
      }
      return L_var4->toByteArray();
   }
}
void o::e__v() {
   if ((o::c_AString == nullptr)) {
      Arr<int16_t> L_var0 = nullptr;
      Arr<int16_t> L_var1 = nullptr;
      try {
         JDataInputStream L_var2{};
         int32_t L_var3{};
         (o::c_AString = newArr<JString>((L_var3 = ((int32_t)(((L_var2 = JDataInputStream::make(o::a_MIDlet->getClass()->getResourceAsStream(JS(u"/a")))))->readShort())))));
         (o::e_Ai = newArr<int32_t>(jshl(int32_t(L_var3),1)));
         for (int32_t L_var4 = 0; (L_var4 < L_var3); (L_var4++)) {
            {
               ([&]() -> decltype(auto) { auto& __a1090 = o::c_AString[L_var4]; auto __v1091 = L_var2->readUTF(); return (__a1090 = __v1091); }());
               ([&]() -> decltype(auto) { auto& __a1092 = o::e_Ai[jshl(int32_t(L_var4),1)]; auto __v1093 = L_var2->readInt(); return (__a1092 = __v1093); }());
               ([&]() -> decltype(auto) { auto& __a1094 = o::e_Ai[jwrap32(jwint((jshl(int32_t(L_var4),1))) + jwint(1))]; auto __v1095 = L_var2->readInt(); return (__a1094 = __v1095); }());
            }
         }
         (o::a_AAs = newArr<Arr<int16_t>>((L_var3 = ((int32_t)(L_var2->readShort())))));
         (o::a_AObject = newArr<Obj>(L_var3));
         (o::a_Az = newArr<bool>(L_var3));
         for (int32_t L_var14 = 0; (L_var14 < L_var3); (L_var14++)) {
            {
               int32_t L_var5 = ((int32_t)(((int16_t)(L_var2->readByte()))));
               int32_t L_var6 = ((int32_t)(L_var2->readByte()));
               (o::a_AAs[L_var14] = newArr<int16_t>(jwrap32(jwint(L_var6) + jwint(2))));
               (o::a_AAs[L_var14][0] = ((int16_t)(L_var5)));
               ([&]() -> decltype(auto) { auto& __a1096 = o::a_AAs[L_var14][1]; auto __v1097 = L_var2->readShort(); return (__a1096 = __v1097); }());
               for (int32_t L_var8 = 0; (L_var8 < L_var6); (L_var8++)) {
                  {
                     ([&]() -> decltype(auto) { auto& __a1098 = o::a_AAs[L_var14][jwrap32(jwint(L_var8) + jwint(2))]; auto __v1099 = L_var2->readShort(); return (__a1098 = __v1099); }());
                  }
               }
            }
         }
         (L_var0 = newArr<int16_t>((L_var3 = ((int32_t)(L_var2->readShort())))));
         (L_var1 = newArr<int16_t>(L_var3));
         for (int32_t L_var15 = 0; (L_var15 < L_var3); (L_var15++)) {
            {
               ([&]() -> decltype(auto) { auto& __a1100 = L_var0[L_var15]; auto __v1101 = L_var2->readShort(); return (__a1100 = __v1101); }());
               ([&]() -> decltype(auto) { auto& __a1102 = L_var1[L_var15]; auto __v1103 = L_var2->readShort(); return (__a1102 = __v1103); }());
            }
         }
         L_var2->close();
         for (int32_t L_var16 = 0; (L_var16 < L_var1.length()); (L_var16++)) {
            {
               int32_t L_var17{};
               if ((((L_var2 = o::a_i_DataInputStream((L_var17 = ((int32_t)(L_var1[L_var16])))))) != nullptr)) {
                  int32_t L_var18 = 0;
                  while (((L_var18 < o::a_Ao.length()) && (!o::a_Ao[L_var18]->a_DataInputStreami_z(L_var2, ((int32_t)(L_var0[L_var16])))))) {
                     {
                        (L_var18++);
                     }
                  }
                  L_var2->close();
               }
            }
         }
         o::a_Ao[0]->a_DataInputStreami_z(nullptr, (-1));
      }
      catch (JIOException& L_var7) {
      }
   }
}
void o::f__v() {
   JVector L_var0 = JVector::make();
   for (int32_t L_var1 = 0; ([&]() { auto __l1104 = L_var1; auto __r1105 = o::a_Vector->size(); return (__l1104 < __r1105); }()); (L_var1++)) {
      {
         int32_t L_var2 = jcast_int(o::a_Vector->elementAt(L_var1));
         if ((!o::a_Az[L_var2])) {
            int32_t L_var3 = 0;
            for (int32_t L_var4 = (-1); (L_var4 < jwrap32(jwint(o::a_AAs[L_var2].length()) - jwint(2))); (L_var4++)) {
               {
                  int32_t L_var5 = ((int32_t)(((L_var4 == (-1)) ? o::a_AAs[L_var2][1] : o::a_AAs[L_var2][jwrap32(jwint(L_var4) + jwint(2))])));
                  int32_t L_var6 = L_var0->size();
                  for (int32_t L_var7 = L_var3; ([&]() { auto __l1106 = L_var7; auto __r1107 = L_var0->size(); return (__l1106 < __r1107); }()); (L_var7++)) {
                     {
                        Arr<int32_t> L_var8 = jcast<Arr<int32_t>>(L_var0->elementAt(L_var7));
                        bool L_var9 = o::c_AString[L_var5].equals(o::c_AString[L_var8[2]]);
                        bool L_var10 = (([&]() { auto __l1108 = L_var7; auto __r1109 = jwrap32(jwint(L_var0->size()) - jwint(1)); return (__l1108 == __r1109); }()) || (!o::c_AString[L_var5].equals(o::c_AString[(jcast<Arr<int32_t>>(L_var0->elementAt(jwrap32(jwint(L_var7) + jwint(1)))))[2]])));
                        if ((L_var9 && (o::e_Ai[jshl(int32_t(L_var5),1)] < o::e_Ai[jshl(int32_t(L_var8[2]),1)]))) {
                           (L_var6 = L_var7);
                           break;
                        }
                        if ((L_var9 && L_var10)) {
                           (L_var6 = jwrap32(jwint(L_var7) + jwint(1)));
                           break;
                        }
                     }
                  }
                  if ((L_var4 == (-1))) {
                     (L_var3 = jwrap32(jwint(L_var6) + jwint(1)));
                  }
                  Arr<int32_t> L_var30{};
                  ([&]() -> decltype(auto) { auto& __a1110 = ((L_var30 = newArr<int32_t>(3)))[0]; auto __v1111 = L_var2; return (__a1110 = __v1111); }());
                  (L_var30[1] = L_var4);
                  (L_var30[2] = L_var5);
                  L_var0->insertElementAt(L_var30, L_var6);
               }
            }
         }
      }
   }
   try {
      JDataInputStream L_var22 = nullptr;
      JString L_var24 = nullptr;
      int32_t L_var26 = 0;
      for (int32_t L_var27 = 0; ([&]() { auto __l1112 = L_var27; auto __r1113 = L_var0->size(); return (__l1112 < __r1113); }()); (L_var27++)) {
         {
            Arr<int32_t> L_var28{};
            int32_t L_var31 = ((L_var28 = jcast<Arr<int32_t>>(L_var0->elementAt(L_var27))))[0];
            int32_t L_var19 = L_var28[2];
            JString L_var32 = o::c_AString[L_var19];
            int32_t L_var33 = o::e_Ai[jshl(int32_t(L_var19),1)];
            int32_t L_var34 = o::e_Ai[jwrap32(jwint((jshl(int32_t(L_var19),1))) + jwint(1))];
            if ((((L_var22 != nullptr) && L_var32.equals(L_var24)) && (L_var26 <= L_var33))) {
               o::a_DataInputStreami_v(L_var22, jwrap32(jwint(L_var33) - jwint(L_var26)));
            } else {
               if ((L_var22 != nullptr)) {
                  L_var22->close();
                  (L_var22 = nullptr);
               }
               if (((L_var33 != (-1)) && (L_var34 != 0))) {
                  (L_var22 = o::a_i_DataInputStream(L_var19));
               }
            }
            bool L_var20 = false;
            if ((L_var28[1] == (-1))) {
               if ((L_var33 == (-1))) {
                  (L_var22 = JDataInputStream::make(o::a_MIDlet->getClass()->getResourceAsStream(jcat(JS(u"/"),L_var32))));
               }
               for (int32_t L_var35 = 0; (L_var35 < o::a_Ao.length()); (L_var35++)) {
                  {
                     Obj L_var28o{};
                     if ((!jsame(((L_var28o = o::a_Ao[L_var35]->a_DataInputStreamiii_Object(((L_var34 != 0) ? L_var22 : static_cast<JDataInputStream>(nullptr)), L_var34, ((int32_t)(o::a_AAs[L_var31][0])), L_var31))),nullptr))) {
                        (o::a_AObject[L_var31] = L_var28o);
                        (L_var20 = true);
                        break;
                     }
                  }
               }
            } else {
               if ((L_var34 != 0)) {
                  for (int32_t L_var11 = 0; (L_var11 < o::a_Ao.length()); (L_var11++)) {
                     {
                        o* L_var10000 = o::a_Ao[L_var11];
                        JString L_var10002 = ((L_var34 == (-1)) ? L_var32 : static_cast<JString>(nullptr));
                        int32_t L_var10004 = ((int32_t)(o::a_AAs[L_var31][0]));
                        int32_t L_var17 = L_var28[1];
                        int32_t L_var15 = L_var10004;
                        JString L_var13 = L_var10002;
                        bool L_var36{};
                        {
                           int32_t L_var20i{};
                           switch (L_var15) {
                           case 2:
                           {
                              L_var20i = ([&]() { auto __l1114 = o::a_Abi_s(jcast<Arr<int8_t>>(o::a_i_Object(L_var31)), 0); auto __r1115 = L_var17; return jwrap32(jwint(__l1114) + jwint(__r1115)); }());
                              if ((L_var22 != nullptr)) {
                                 Arr<int8_t> L_var12 = o::a_InputStreami_Ab(L_var22, L_var34);
                                 ([&]() -> decltype(auto) { auto& __a1116 = o::a_AImage[L_var20i]; auto __v1117 = JImage::createImage(L_var12, 0, L_var12.length()); return (__a1116 = __v1117); }());
                              } else {
                                 ([&]() -> decltype(auto) { auto& __a1118 = o::a_AImage[L_var20i]; auto __v1119 = JImage::createImage(jcat(JS(u"/"),L_var13)); return (__a1118 = __v1119); }());
                              }
                              (L_var36 = true);
                              break;
                           }
                           case 3:
                           case 8:
                           {
                              if ((L_var22 != nullptr)) {
                                 ([&]() -> decltype(auto) { auto __p1120 = o::a_InputStreami_Ab(L_var22, L_var34); auto __p1121 = L_var31; auto __p1122 = nullptr; return o::a_AbiString_v(__p1120, __p1121, nullptr); }());
                              } else {
                                 o::a_AbiString_v(nullptr, L_var31, jcat(JS(u"/"),L_var13));
                              }
                              (L_var36 = true);
                              break;
                           }
                           case 4:
                           case 5:
                           case 6:
                           case 7:
                           default:
                           {
                              (L_var36 = false);
                           }
                           }
                        }
                        (L_var20 = L_var36);
                        if (L_var36) {
                           break;
                        }
                     }
                  }
               }
            }
            if (((!L_var20) && (L_var33 != (-1)))) {
               o::a_DataInputStreami_v(L_var22, L_var34);
            }
            if ((L_var22 != nullptr)) {
               (L_var24 = L_var32);
               (L_var26 = jwrap32(jwint(L_var33) + jwint(L_var34)));
            }
         }
      }
      if ((L_var22 != nullptr)) {
         L_var22->close();
      }
   }
   catch (JIOException& L_var18) {
   }
   for (int32_t L_var23 = 0; ([&]() { auto __l1123 = L_var23; auto __r1124 = o::a_Vector->size(); return (__l1123 < __r1124); }()); (L_var23++)) {
      {
         int32_t L_var25 = jcast_int(o::a_Vector->elementAt(L_var23));
         (o::a_Az[L_var25] = true);
      }
   }
   o::a_Vector->removeAllElements();
}
void o::g__v() {
   for (int32_t L_var0 = 0; ([&]() { auto __l1125 = L_var0; auto __r1126 = o::b_Vector->size(); return (__l1125 < __r1126); }()); (L_var0++)) {
      {
         int32_t L_var1 = jcast_int(o::b_Vector->elementAt(L_var0));
         if (o::a_Az[L_var1]) {
            int32_t L_var2 = ((int32_t)(o::a_AAs[L_var1][0]));
            for (int32_t L_var3 = 0; (L_var3 < o::a_Ao.length()); (L_var3++)) {
               {
                  o* L_var10000 = o::a_Ao[L_var3];
                  int32_t L_var6 = L_var1;
                  bool L_var16{};
                  {
                     Arr<int8_t> L_var9{};
                     int32_t L_var11{};
                     int32_t L_var13{};
                     Arr<int16_t> L_var4{};
                     switch (L_var2) {
                     case 2:
                     {
                        L_var9 = jcast<Arr<int8_t>>(o::a_AObject[L_var1]);
                        for (int32_t L_var10 = 0; (L_var10 < o::a_As.length()); (L_var10 += 2)) {
                           {
                              if ((o::a_As[L_var10] == L_var6)) {
                                 (o::a_As[L_var10] = ((int16_t)((-1))));
                                 (o::a_As[jwrap32(jwint(L_var10) + jwint(1))] = ((int16_t)((-1))));
                              }
                           }
                        }
                        L_var11 = ((int32_t)(o::a_Abi_s(L_var9, 0)));
                        L_var13 = ((int32_t)(o::a_Abi_s(L_var9, 2)));
                        for (int32_t L_var7 = 0; (L_var7 < o::a_Ab.length()); (L_var7 += 7)) {
                           {
                              int32_t L_var8{};
                              if ((([&]() { auto __l1127 = ((L_var8 = ((int32_t)(o::a_Ab[jwrap32(jwint(L_var7) + jwint(6))])))); auto __r1128 = L_var11; return (__l1127 >= __r1128); }()) && (L_var8 < L_var13))) {
                                 for (int32_t L_var15 = 0; (L_var15 < 7); (L_var15++)) {
                                    {
                                       (o::a_Ab[jwrap32(jwint(L_var7) + jwint(L_var15))] = ((int8_t)((-1))));
                                    }
                                 }
                              }
                           }
                        }
                        (L_var11 = ((int32_t)(o::a_Abi_s(L_var9, 2))));
                        for (int32_t L_var14 = ((int32_t)(o::a_Abi_s(L_var9, 0))); (L_var14 < L_var11); (L_var14++)) {
                           {
                              (o::a_AImage[L_var14] = nullptr);
                           }
                        }
                        (L_var16 = true);
                        break;
                     }
                     case 3:
                     {
                        (L_var16 = true);
                        break;
                     }
                     case 4:
                     {
                        for (int32_t L_var5 = ((int32_t)(((L_var4 = jcast<Arr<int16_t>>(o::a_AObject[L_var1])))[0])); (L_var5 < jwrap32(jwint(L_var4[1]) + jwint(L_var4[0]))); (L_var5++)) {
                           {
                              (o::d_AString[L_var5] = nullptr);
                           }
                        }
                        (L_var16 = true);
                        break;
                     }
                     case 5:
                     case 6:
                     case 7:
                     default:
                     {
                        (L_var16 = false);
                     }
                     }
                  }
                  if (L_var16) {
                     break;
                  }
               }
            }
            (o::a_AObject[L_var1] = nullptr);
            (o::a_Az[L_var1] = false);
         }
      }
   }
   o::b_Vector->removeAllElements();
}
int16_t o::a_Abi_s(Arr<int8_t> L_var0, int32_t L_var1) {
   return ((int16_t)(((jshl(int32_t(L_var0[L_var1]),8) | (L_var0[jwrap32(jwint(L_var1) + jwint(1))] & 255)))));
}
JDataInputStream o::a_i_DataInputStream(int32_t L_var0) {
   if ((o::e_Ai[jwrap32(jwint((jshl(int32_t(L_var0),1))) + jwint(1))] != 0)) {
      JInputStream L_var1 = o::a_MIDlet->getClass()->getResourceAsStream(jcat(JS(u"/"),o::c_AString[L_var0]));
      JDataInputStream L_var2 = JDataInputStream::make(L_var1);
      if ((o::e_Ai[jshl(int32_t(L_var0),1)] != (-1))) {
         o::a_DataInputStreami_v(L_var2, o::e_Ai[jshl(int32_t(L_var0),1)]);
      }
      return L_var2;
   } else {
      return static_cast<JDataInputStream>(nullptr);
   }
}
bool o::a_DataInputStreami_z(JDataInputStream L_var1, int32_t L_var2) {
   {
      int32_t L_var5{};
      switch (L_var2) {
      case (-1):
      {
         (o::a_As = newArr<int16_t>(428));
         (o::a_Ab = newArr<int8_t>(2282));
         (o::a_AImage = newArr<JImage>(46));
         for (int32_t L_var6 = 0; (L_var6 < o::a_As.length()); (L_var6++)) {
            {
               (o::a_As[L_var6] = ((int16_t)((-1))));
            }
         }
         for (int32_t L_var7 = 0; (L_var7 < o::a_Ab.length()); (L_var7++)) {
            {
               (o::a_Ab[L_var7] = ((int8_t)((-1))));
            }
         }
      }
      case 0:
      case 1:
      case 2:
      case 3:
      case 5:
      default:
      {
         break;
      }
      case 4:
      {
         (o::o_i = ((int32_t)(L_var1->readByte())));
         (o::d_AString = newArr<JString>(L_var1->readShort()));
         break;
      }
      case 6:
      {
         (o::b_AAs = newArr<Arr<int16_t>>((L_var5 = ((int32_t)(L_var1->readShort())))));
         for (int32_t L_var8 = 0; (L_var8 < L_var5); (L_var8++)) {
            {
               int32_t L_var3 = ((int32_t)(L_var1->readShort()));
               (o::b_AAs[L_var8] = newArr<int16_t>(L_var3));
               for (int32_t L_var4 = 0; (L_var4 < L_var3); (L_var4++)) {
                  {
                     ([&]() -> decltype(auto) { auto& __a1129 = o::b_AAs[L_var8][L_var4]; auto __v1130 = L_var1->readShort(); return (__a1129 = __v1130); }());
                  }
               }
            }
         }
         return true;
      }
      case 7:
      {
         return true;
      }
      }
   }
   return false;
}
Obj o::a_DataInputStreamiii_Object(JDataInputStream L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4) {
   {
      int32_t L_var10{};
      int32_t L_var14{};
      int32_t L_var17{};
      int32_t L_var19{};
      int32_t L_var21{};
      JByteArrayOutputStream L_var22{};
      JDataOutputStream L_var23{};
      int32_t L_var12{};
      int32_t L_var13{};
      int32_t L_var9{};
      int32_t L_var5{};
      switch (L_var3) {
      case 2:
      {
         L_var10 = ((int32_t)(L_var1->readByte()));
         L_var14 = ((int32_t)(L_var1->readShort()));
         L_var17 = ((int32_t)(L_var1->readShort()));
         L_var19 = ((int32_t)(L_var1->readShort()));
         L_var21 = ((int32_t)(L_var1->readShort()));
         for (int32_t L_var7 = 0; (L_var7 < L_var17); (L_var7++)) {
            {
               int32_t L_var8 = ((int32_t)(L_var1->readShort()));
               (o::a_As[jshl(int32_t(jwrap32(jwint(L_var8) - jwint(326))),1)] = ((int16_t)(L_var4)));
               ([&]() -> decltype(auto) { auto& __a1131 = o::a_As[jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var8) - jwint(326))),1))) + jwint(1))]; auto __v1132 = ((int16_t)((jwrap32(jwint(L_var1->readShort()) + jwint(4))))); return (__a1131 = __v1132); }());
            }
         }
         L_var22 = JByteArrayOutputStream::make(jwrap32(jwint(L_var19) + jwint(4)));
         ((L_var23 = JDataOutputStream::make(L_var22)))->writeShort(L_var14);
         L_var23->writeShort(jwrap32(jwint(L_var14) + jwint(L_var10)));
         for (int32_t L_var11 = 0; (L_var11 < L_var19); (L_var11++)) {
            {
               L_var23->writeByte(L_var1->readByte());
            }
         }
         L_var12 = 0;
         for (int32_t L_var15 = 0; (L_var15 < jshl(int32_t(L_var21),3)); (L_var15++)) {
            {
               if ((((L_var15 & 7)) == 0)) {
                  (L_var12 = jwrap32(jwint(7) * jwint(L_var1->readShort())));
               } else {
                  ([&]() -> decltype(auto) { auto& __a1133 = o::a_Ab[jwrap32(jwint(jwrap32(jwint(L_var12) + jwint(((L_var15 & 7))))) - jwint(1))]; auto __v1134 = L_var1->readByte(); return (__a1133 = __v1134); }());
               }
            }
         }
         return Obj(L_var22->toByteArray());
      }
      case 3:
      {
         return JObject::make();
      }
      case 4:
      {
         L_var13 = ((int32_t)(L_var1->readShort()));
         L_var9 = ((int32_t)(L_var1->readShort()));
         (L_var3 = (-999999));
         (L_var4 = (-999999));
         L_var5 = 0;
         for (int32_t L_var6 = 0; (L_var6 < jwrap32(jwint(o::o_i) + jwint(1))); (L_var6++)) {
            {
               if ((L_var6 == 0)) {
                  (L_var3 = L_var1->readInt());
               } else {
                  (L_var5 = L_var1->readInt());
                  if ((L_var6 == 1)) {
                     (L_var4 = jwrap32(jwint(L_var5) - jwint(L_var3)));
                  }
               }
            }
         }
         o::a_DataInputStreami_v(L_var1, L_var3);
         for (int32_t L_var20 = 0; (L_var20 < L_var13); (L_var20++)) {
            {
               if ((o::d_AString[jwrap32(jwint(L_var9) + jwint(L_var20))] == nullptr)) {
                  ([&]() -> decltype(auto) { auto& __a1135 = o::d_AString[jwrap32(jwint(L_var9) + jwint(L_var20))]; auto __v1136 = L_var1->readUTF(); return (__a1135 = __v1136); }());
               } else {
                  L_var1->readUTF();
               }
            }
         }
         o::a_DataInputStreami_v(L_var1, jwrap32(jwint(L_var5) - jwint((jwrap32(jwint(L_var3) + jwint(L_var4))))));
         return Obj(Arr<int16_t>({((int16_t)(L_var9)), ((int16_t)(L_var13))}));
      }
      case 5:
      case 6:
      case 7:
      default:
      {
         return Obj(o::a_InputStreami_Ab(L_var1, L_var2));
      }
      }
   }
}
void o::g_i_v(int32_t L_var0) {
   Arr<int16_t> L_var2 = o::b_AAs[0];
   for (int32_t L_var1 = 0; (L_var1 < L_var2.length()); (L_var1++)) {
      {
         o::e_i_v(((int32_t)(L_var2[L_var1])));
      }
   }
}
JImage o::a_i_Image(int32_t L_var0) {
   int32_t L_var1{};
   return ((((L_var1 = o::d_i_i(L_var0))) >= 0) ? o::a_AImage[L_var1] : static_cast<JImage>(nullptr));
}
void o::a_iImage_v(int32_t L_var0, JImage L_var1) {
   if ((((L_var0 = o::d_i_i(L_var0))) >= 0)) {
      (o::a_AImage[L_var0] = L_var1);
   }
}
int32_t o::d_i_i(int32_t L_var0) {
   if ((L_var0 == (-1))) {
      return (-1);
   } else {
      if ((L_var0 < (-1))) {
         return (-1);
      } else {
         Arr<int8_t> L_var4 = nullptr;
         int32_t L_var1{};
         int32_t L_var2{};
         int32_t L_var9{};
         if ((L_var0 < 326)) {
            (L_var1 = (-99));
            (L_var2 = 0);
            (L_var9 = 0);
            if ((o::a_Ab[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(7))) + jwint(6))] == (-1))) {
               return (-1);
            }
         } else {
            int32_t L_var5{};
            if (([&]() { auto __l1137 = ((L_var5 = jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1))) + jwint(1)))); auto __r1138 = o::a_As.length(); return (__l1137 >= __r1138); }())) {
               return (-1);
            }
            (L_var9 = ((int32_t)(o::a_As[L_var5])));
            int32_t L_var7{};
            if ((((L_var7 = ((int32_t)(o::a_As[jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1)])))) < 0)) {
               return (-1);
            }
            (L_var4 = jcast<Arr<int8_t>>(o::a_AObject[L_var7]));
            if (((L_var9 == (-1)) || (L_var4 == nullptr))) {
               return (-1);
            }
            int32_t L_var8{};
            (L_var1 = (((L_var8 = ((int32_t)(L_var4[(L_var9++)])))) & 3));
            (L_var2 = ((((L_var8 & 4)) != 0) ? 2 : 1));
         }
         int32_t L_var11 = (-1);
         if (((L_var1 == 0) || (L_var1 == (-99)))) {
            if ((L_var1 == 0)) {
               if ((L_var2 == 2)) {
                  (L_var9 += 12);
               } else {
                  (L_var9 += 6);
               }
               (L_var11 = ((int32_t)(((int16_t)(((jshl(int32_t(L_var4[L_var9]),8) | (L_var4[jwrap32(jwint(L_var9) + jwint(1))] & 255))))))));
            } else {
               (L_var0 *= 7);
               (L_var11 = ((int32_t)(((int16_t)(o::a_Ab[jwrap32(jwint(L_var0) + jwint(6))])))));
            }
         }
         return L_var11;
      }
   }
}
void o::a_iii_v(int32_t L_var0, int32_t L_var1, int32_t L_var2) {
   Arr<int8_t> L_var6 = nullptr;
   int32_t L_var3{};
   int32_t L_var4{};
   int32_t L_var18{};
   if ((L_var2 < 326)) {
      (L_var3 = (-99));
      (L_var4 = 0);
      (L_var18 = 0);
   } else {
      (L_var18 = ((int32_t)(o::a_As[jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var2) - jwint(326))),1))) + jwint(1))])));
      int32_t L_var7{};
      (L_var3 = (((L_var7 = ((int32_t)(((L_var6 = jcast<Arr<int8_t>>(o::a_AObject[o::a_As[jshl(int32_t(jwrap32(jwint(L_var2) - jwint(326))),1)]])))[(L_var18++)])))) & 3));
      (L_var4 = ((((L_var7 & 4)) != 0) ? 2 : 1));
   }
   if (((L_var3 != 0) && (L_var3 != (-99)))) {
      if ((L_var3 == 1)) {
         (L_var18 += jshl(int32_t(L_var4),2));
         int32_t L_var24 = ((int32_t)(((int16_t)(((jshl(int32_t(L_var6[L_var18]),8) | (L_var6[jwrap32(jwint(L_var18) + jwint(1))] & 255)))))));
         (L_var18 += 2);
         if ((L_var4 == 2)) {
            for (int32_t L_var16 = 0; (L_var16 < L_var24); (L_var16++)) {
               {
                  o::a_iii_v(jwrap32(jwint(L_var0) + jwint(((int16_t)(((jshl(int32_t(L_var6[L_var18]),8) | (L_var6[jwrap32(jwint(L_var18) + jwint(1))] & 255))))))), jwrap32(jwint(L_var1) + jwint(((int16_t)(((jshl(int32_t(L_var6[jwrap32(jwint(L_var18) + jwint(2))]),8) | (L_var6[jwrap32(jwint(L_var18) + jwint(3))] & 255))))))), ((int32_t)(((int16_t)(((jshl(int32_t(L_var6[jwrap32(jwint(L_var18) + jwint(4))]),8) | (L_var6[jwrap32(jwint(L_var18) + jwint(5))] & 255))))))));
                  (L_var18 += 6);
               }
            }
            return;
         }
         for (int32_t L_var15 = 0; (L_var15 < L_var24); (L_var15++)) {
            {
               ([&]() -> decltype(auto) { auto __p1143 = ([&]() { auto __l1139 = L_var0; auto __r1140 = L_var6[(L_var18++)]; return jwrap32(jwint(__l1139) + jwint(__r1140)); }()); auto __p1144 = ([&]() { auto __l1141 = L_var1; auto __r1142 = L_var6[(L_var18++)]; return jwrap32(jwint(__l1141) + jwint(__r1142)); }()); auto __p1145 = L_var6[(L_var18++)]; return o::a_iii_v(__p1143, __p1144, ((int32_t)(__p1145))); }());
            }
         }
      }
   } else {
      JImage L_var23{};
      if ((L_var3 == 0)) {
         if ((L_var4 == 2)) {
            for (int32_t L_var10 = 0; (L_var10 < 6); (L_var10++)) {
               {
                  (o::b_As[L_var10] = ((int16_t)(((jshl(int32_t(L_var6[L_var18]),8) | (L_var6[jwrap32(jwint(L_var18) + jwint(1))] & 255))))));
                  (L_var18 += 2);
               }
            }
         } else {
            for (int32_t L_var11 = 0; (L_var11 < 6); (L_var11++)) {
               {
                  ([&]() -> decltype(auto) { auto& __a1146 = o::b_As[L_var11]; auto __v1147 = ((int16_t)(L_var6[(L_var18++)])); return (__a1146 = __v1147); }());
               }
            }
         }
         (L_var23 = o::a_AImage[((int16_t)(((jshl(int32_t(L_var6[L_var18]),8) | (L_var6[jwrap32(jwint(L_var18) + jwint(1))] & 255)))))]);
      } else {
         (L_var2 *= 7);
         (o::b_As[0] = ((int16_t)(((o::a_Ab[L_var2] & 255)))));
         (o::b_As[1] = ((int16_t)(((o::a_Ab[jwrap32(jwint(L_var2) + jwint(1))] & 255)))));
         (o::b_As[2] = ((int16_t)(o::a_Ab[jwrap32(jwint(L_var2) + jwint(2))])));
         (o::b_As[3] = ((int16_t)(o::a_Ab[jwrap32(jwint(L_var2) + jwint(3))])));
         (o::b_As[4] = ((int16_t)(((o::a_Ab[jwrap32(jwint(L_var2) + jwint(4))] & 255)))));
         (o::b_As[5] = ((int16_t)(((o::a_Ab[jwrap32(jwint(L_var2) + jwint(5))] & 255)))));
         (L_var23 = o::a_AImage[o::a_Ab[jwrap32(jwint(L_var2) + jwint(6))]]);
      }
      (L_var0 -= o::b_As[2]);
      (L_var1 -= o::b_As[3]);
      int32_t L_var13 = 0;
      o::b_Graphics->getClipX();
      o::b_Graphics->getClipY();
      o::b_Graphics->getClipWidth();
      o::b_Graphics->getClipHeight();
      (L_var13 = ((int32_t)(o::b_As[0])));
      int32_t L_var17 = ((int32_t)(o::b_As[1]));
      if (((L_var13 <= 0) || (L_var17 <= 0))) {
         return;
      }
      if ((o::n_i == (-1))) {
         o::b_Graphics->drawRegion(L_var23, o::b_As[4], o::b_As[5], L_var13, L_var17, 0, L_var0, L_var1, 20);
         return;
      }
      o::b_Graphics->drawRegion(L_var23, o::b_As[4], o::b_As[5], L_var13, L_var17, o::n_i, L_var0, L_var1, 20);
      (o::n_i = (-1));
   }
}
void o::a_iiii_v(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3) {
   (L_var0 += o::a_ii_i(L_var2, 2));
   (L_var1 += o::a_ii_i(L_var2, 3));
   if ((((L_var3 & 1)) == 1)) {
      (L_var0 -= jdiv(int32_t(o::a_ii_i(L_var2, 0)),int32_t(2)));
   }
   if ((((L_var3 & 8)) == 8)) {
      (L_var0 -= o::a_ii_i(L_var2, 0));
   }
   if ((((L_var3 & 2)) == 2)) {
      (L_var1 -= jdiv(int32_t(o::a_ii_i(L_var2, 1)),int32_t(2)));
   }
   if ((((L_var3 & 32)) == 32)) {
      (L_var1 -= o::a_ii_i(L_var2, 1));
   }
   o::a_iii_v(L_var0, L_var1, L_var2);
}
void o::a_iiiii_v(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3, int32_t L_var4) {
   (o::n_i = 6);
   o::a_iiii_v(L_var0, L_var1, 12, 24);
}
int32_t o::a_ii_i(int32_t L_var0, int32_t L_var1) {
   if ((L_var0 < 326)) {
      return (((L_var1 != 2) && (L_var1 != 3)) ? (o::a_Ab[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(7))) + jwint(L_var1))] & 0xFF) : ((int32_t)(o::a_Ab[jwrap32(jwint(jwrap32(jwint(L_var0) * jwint(7))) + jwint(L_var1))])));
   } else {
      int32_t L_var2 = ((int32_t)(o::a_As[jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1))) + jwint(1))]));
      Arr<int8_t> L_var4{};
      if (((((((((L_var4 = jcast<Arr<int8_t>>(o::a_AObject[o::a_As[jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1)]])))[(L_var2++)] & 4)) != 0) ? 2 : 1)) == 2)) {
         (L_var2 += jshl(int32_t(L_var1),1));
         return ((int32_t)(((int16_t)(((jshl(int32_t(L_var4[L_var2]),8) | (L_var4[jwrap32(jwint(L_var2) + jwint(1))] & 0xFF)))))));
      } else {
         return ((int32_t)(L_var4[jwrap32(jwint(L_var2) + jwint(L_var1))]));
      }
   }
}
int32_t o::b_ii_i(int32_t L_var0, int32_t L_var1) {
   int32_t L_var2 = ((int32_t)(o::a_As[jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1))) + jwint(1))]));
   int32_t L_var3{};
   Arr<int8_t> L_var5{};
   int32_t L_var4 = (((L_var3 = ((int32_t)(((L_var5 = jcast<Arr<int8_t>>(o::a_AObject[o::a_As[jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1)]])))[(L_var2++)])))) & 3);
   (L_var3 = ((((L_var3 & 4)) != 0) ? 2 : 1));
   if ((L_var4 == 1)) {
      (L_var2 += jshl(int32_t(L_var3),2));
      int32_t L_var12 = ((int32_t)(o::a_Abi_s(L_var5, L_var2)));
      (L_var2 += 2);
      int32_t L_var9{};
      (L_var2 = ([&]() { auto __l1148 = ((L_var9 = jwrap32(jwint(L_var2) + jwint(jwrap32(jwint(jwrap32(jwint(L_var3) * jwint(3))) * jwint(L_var12)))))); auto __r1149 = jwrap32(jwint((jshl(int32_t(L_var3),1))) * jwint(L_var1)); return jwrap32(jwint(__l1148) + jwint(__r1149)); }()));
      return ((L_var3 == 1) ? ((jshl(int32_t(L_var5[L_var2]),16) & (-65536)) | (L_var5[jwrap32(jwint(L_var2) + jwint(1))] & 65535)) : ([&]() { auto __l1150 = (jshl(int32_t(o::a_Abi_s(L_var5, L_var2)),16) & (-65536)); auto __r1151 = (o::a_Abi_s(L_var5, jwrap32(jwint(L_var2) + jwint(2))) & 65535); return (__l1150 | __r1151); }()));
   } else {
      return 0;
   }
}
void o::b_iiii_v(int32_t L_var0, int32_t L_var1, int32_t L_var2, int32_t L_var3) {
   ([&]() -> decltype(auto) { auto __p1152 = L_var0; auto __p1153 = L_var1; auto __p1154 = o::c_ii_i(L_var2, L_var3); return o::a_iii_v(__p1152, __p1153, __p1154); }());
}
int32_t o::c_ii_i(int32_t L_var0, int32_t L_var1) {
   int32_t L_var2 = ((int32_t)(o::a_As[jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1))) + jwint(1))]));
   Arr<int8_t> L_var3 = jcast<Arr<int8_t>>(o::a_AObject[o::a_As[jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1)]]);
   (L_var2 += 3);
   (L_var2 += jwrap32(jwint(L_var1) * jwint(2)));
   return (jshl(int32_t(L_var3[L_var2]),8) | (L_var3[jwrap32(jwint(L_var2) + jwint(1))] & 0xFF));
}
int32_t o::b_i_i(int32_t L_var0) {
   int32_t L_var1 = ((int32_t)(o::a_As[jwrap32(jwint((jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1))) + jwint(1))]));
   Arr<int8_t> L_var2 = jcast<Arr<int8_t>>(o::a_AObject[o::a_As[jshl(int32_t(jwrap32(jwint(L_var0) - jwint(326))),1)]]);
   return ((int32_t)(([&]() -> decltype(auto) { auto __p1155 = L_var2; auto __p1156 = (++L_var1); return o::a_Abi_s(__p1155, __p1156); }())));
}
void o::a_z_v(bool L_var0) {
   (o::i_z = true);
}
bool o::c__z() {
   return o::i_z;
}
void o::a_AbiString_v(Arr<int8_t> L_var0, int32_t L_var1, JString L_var2) {
   if ((L_var0 == nullptr)) {
      JInputStream L_var6 = o::a_MIDlet->getClass()->getResourceAsStream(L_var2);
      try {
         (L_var0 = o::a_InputStreami_Ab(L_var6, (-1)));
      }
      catch (JException& L_var3) {
      }
   }
   if ((L_var1 >= 0)) {
      (o::a_AObject[L_var1] = Obj(L_var0));
      (o::a_Az[L_var1] = (L_var0 != nullptr));
   }
}
void o::c_ii_v(int32_t L_var0, int32_t L_var1) {
   {
      if (o::e_z) {
         if ((L_var1 == (-1))) {
            (o::g_i = L_var0);
         } else {
            (o::g_i = (-1));
         }
      } else {
         (o::g_i = (-1));
         Arr<int8_t> L_var3{};
         if ((((L_var3 = jcast<Arr<int8_t>>(o::a_i_Object(L_var0)))) != nullptr)) {
            o::d__v();
            if (o::i_z) {
               try {
                  if ((L_var1 == (-1))) {
                     (L_var1 = (-1));
                     (o::r_i = L_var0);
                  }
                  ((o::a_Player = JManager::createPlayer(JByteArrayInputStream::make(L_var3), JS(u"audio/midi"))))->prefetch();
                  JVolumeControl L_var6{};
                  if ((((L_var6 = o::a_Player->getControl(JS(u"VolumeControl")))) != nullptr)) {
                     L_var6->setLevel(o::q_i);
                  }
                  o::a_Player->setLoopCount(L_var1);
                  o::a_Player->start();
               }
               catch (JException& L_var4) {
               }
            }
         }
      }
   }
}
void o::d__v() {
   {
      (o::g_i = (-1));
      if ((o::i_z && (o::a_Player != nullptr))) {
         try {
            if ((o::a_Player->getState() != 0)) {
               o::a_Player->stop();
               o::a_Player->deallocate();
               o::a_Player->close();
            }
         }
         catch (JException& L_var2) {
         }
         (o::r_i = (-1));
         (o::a_Player = nullptr);
      }
   }
}
void o::b_z_v(bool L_var0) {
   JDeviceControl::setLights(0, 100);
}
void o::h_i_v(int32_t L_var0) {
   {
      (o::t_i = 0);
      (o::v_i = 0);
      (o::u_i = 0);
      if ((L_var0 == 1)) {
         (o::a_o = (o::__ci(), new o()));
         JThread::make(o::a_o)->start();
      } else {
         if ((o::a_o != nullptr)) {
            if (((L_var0 != 2) && (L_var0 != 4))) {
               if (((((L_var0 == 3) || (L_var0 == 5))) && o::d_z)) {
                  (o::d_z = false);
                  jobj_notifyAll(o::b_Object);
               }
            } else {
               if ((!o::d_z)) {
                  (o::d_z = true);
                  (o::e_z = true);
                  (L_var0 = o::r_i);
                  o::d__v();
                  (o::g_i = L_var0);
               }
            }
         }
      }
   }
}
void o::run() {
   try {
      if (o::a_z) {
         {
            try {
               jobj_wait(o::a_Object, (int64_t)500LL);
               while (o::f_z) {
                  {
                     o::j__v();
                     this->j_i_v(2);
                     jobj_wait(o::a_Object, ((int64_t)(o::d_i)));
                  }
               }
            }
            catch (JInterruptedException& L_var10) {
            }
         }
      } else {
         (o::a_z = true);
         (o::a_Ai = newArr<int32_t>(20));
         (o::e_i = 0);
         (o::b_Ai = newArr<int32_t>(40));
         (o::f_i = 0);
         (o::f_Ai = newArr<int32_t>(20));
         (o::w_i = 0);
         (o::a_AString = newArr<JString>(3));
         (o::b_AString = newArr<JString>(3));
         (o::c_Ai = newArr<int32_t>(3));
         JDisplay::getDisplay(o::a_MIDlet)->setCurrent(this);
         this->setFullScreenMode(true);
         o::j__v();
         (o::a_Vector = JVector::make());
         (o::b_Vector = JVector::make());
         ([&]() -> decltype(auto) { auto& __a1157 = ((o::a_Ao = newArr<o*>(1)))[0]; auto __v1158 = o::a_o; return (__a1157 = __v1158); }());
         (o::a_m = (m::__ci(), new m()));
         o::i_i_v(1);
         o::h__v();
         while ((!o::g_z)) {
            {
               try {
                  (o::a_l = JSystem::currentTimeMillis());
                  if ((!o::b_z)) {
                     (o::e_z = true);
                  }
                  o::j__v();
                  if ((o::e_i > 0)) {
                     {
                        for (int32_t L_var2 = 0; (L_var2 < o::e_i); (L_var2++)) {
                           {
                              o::a_m->c_i_v(o::a_Ai[L_var2]);
                              (o::a_Ai[L_var2] = 0);
                           }
                        }
                        (o::e_i = 0);
                     }
                     {
                        if ((o::g_i != (-1))) {
                           o::c_ii_v(o::g_i, (-1));
                           (o::g_i = (-1));
                        }
                     }
                  }
                  if (o::d__z()) {
                     for (int32_t L_var16 = 0; (L_var16 < o::a_AString.length()); (L_var16++)) {
                        {
                           (o::b_AString[L_var16] = nullptr);
                        }
                     }
                     this->i__v();
                     (o::a_l = JSystem::currentTimeMillis());
                  }
                  if (o::e_z) {
                     o::l__v();
                  } else {
                     for (int32_t L_var17 = 0; (L_var17 < o::a_AString.length()); (L_var17++)) {
                        {
                           if ((o::b_AString[L_var17] != o::a_AString[L_var17])) {
                              if (((o::b_AString[L_var17] != nullptr) && o::b_AString[L_var17].equals(o::a_AString[L_var17]))) {
                                 (o::a_AString[L_var17] = o::b_AString[L_var17]);
                              } else {
                                 (o::b_AString[L_var17] = o::a_AString[L_var17]);
                              }
                           }
                        }
                     }
                     this->j_i_v(1);
                     if (o::e_z) {
                        o::l__v();
                     } else {
                        o::k__v();
                        if ((!o::g_z)) {
                           if (o::l_z) {
                              int32_t L_var18 = o::z_i;
                              if ((((o::z_i >= 10) && (L_var18 <= 19)) && (([&]() { auto __l1159 = JSystem::currentTimeMillis(); auto __r1160 = o::d_l; return jwrap64(jwlong(__l1159) - jwlong(__r1160)); }()) > (int64_t)500LL))) {
                                 o::k_i_v(L_var18);
                              }
                           }
                           if (o::e_z) {
                              o::l__v();
                           } else {
                              JThread::sleep((int64_t)1LL);
                           }
                        }
                     }
                  }
               }
               catch (JThrowable& L_var13) {
               }
            }
         }
         (o::a_m = nullptr);
         o::d__v();
         for (int32_t L_var19 = 0; (L_var19 < o::a_AObject.length()); (L_var19++)) {
            {
               o::b_Vector->addElement(JInteger::make(L_var19));
            }
         }
         o::g__v();
         o::a_MIDlet->notifyDestroyed();
      }
   }
   catch (JThrowable& L_var14) {
   }
}
void o::h__v() {
   (o::b_l = (int64_t)0LL);
   (o::a_i = 0);
   o::c__v();
}
bool o::d__z() {
   return (((o::a_Vector->size() > 0) || (o::b_Vector->size() > 0)) || (o::f_i > 0));
}
void o::i__v() {
   (o::f_z = true);
   JThread::make(o::a_o)->start();
   o::e__v();
   int32_t L_var3 = 0;
   int32_t L_var1 = 0;
   while ((((L_var3 < o::f_i) || (!o::a_Vector->isEmpty())) || (!o::b_Vector->isEmpty()))) {
      {
         if ((!o::b_Vector->isEmpty())) {
            o::g__v();
            JSystem::gc();
         }
         if ((!o::a_Vector->isEmpty())) {
            o::f__v();
            JSystem::gc();
         }
         if (((L_var3 < o::f_i) && (((L_var1 = o::a_m->b_ii_i(o::b_Ai[L_var3], L_var1))) == 0))) {
            (L_var3++);
         }
      }
   }
   {
      (o::f_z = false);
      jobj_notify(o::a_Object);
   }
   (o::f_i = 0);
   o::h__v();
}
void o::j__v() {
   int32_t L_var0 = o::a_o->getWidth();
   int32_t L_var1 = o::a_o->getHeight();
   if (((o::b_i != L_var0) || (o::c_i != L_var1))) {
      (o::b_i = L_var0);
      (o::c_i = L_var1);
      if ((o::a_m != nullptr)) {
         o::i_i_v(2);
      }
   }
}
void o::j_i_v(int32_t L_var1) {
   (o::j_i = L_var1);
   JGraphics L_var2 = o::a_o->getGraphics();
   this->b_Graphics_v(L_var2);
   o::a_o->flushGraphics();
   (o::j_i = 0);
}
void o::k__v() {
   int64_t L_var0 = JSystem::currentTimeMillis();
   if ((o::b_l != (int64_t)0LL)) {
      if (([&]() { auto __l1163 = ((o::a_i = ([&]() { auto __l1161 = ((o::a_i = ((int32_t)((jwrap64(jwlong(L_var0) - jwlong(o::b_l))))))); auto __r1162 = o::i_i; return jdiv(int32_t(__l1161),int32_t(__r1162)); }()))); auto __r1164 = o::h_i; return (__l1163 > __r1164); }())) {
         (o::a_i = o::h_i);
      }
   } else {
      (o::a_i = 0);
   }
   (o::b_l = L_var0);
   (o::k_z = false);
   for (int32_t L_var2 = 0; (L_var2 < o::i_i); (L_var2++)) {
      {
         for (int32_t L_var1 = 0; (L_var1 < o::w_i); (L_var1++)) {
            {
               o::a_m->b_i_v(o::f_Ai[L_var1]);
               (o::f_Ai[L_var1] = (-1));
            }
         }
         (o::w_i = 0);
         (o::v_i = (o::t_i | o::u_i));
         (o::u_i = 0);
         int32_t L_var3 = o::a_m->a_i_i(0);
         while ((L_var3 != 0)) {
            {
               (L_var3 = o::a_m->a_i_i(L_var3));
            }
         }
         if (o::d__z()) {
            break;
         }
      }
   }
}
void o::l__v() {
   {
      if ((!o::d__z())) {
         (o::e_z = false);
         o::i_i_v(3);
      }
      if (o::d_z) {
         try {
            jobj_wait(o::b_Object);
         }
         catch (JInterruptedException& L_var2) {
         }
      }
   }
   o::h__v();
}
void o::b_Graphics_v(JGraphics L_var1) {
   if ((o::j_i != 0)) {
      try {
         (o::a_Graphics = L_var1);
         (o::b_Graphics = L_var1);
         L_var1->setClip(0, 0, o::b_i, o::c_i);
         if ((o::a_m == nullptr)) {
            L_var1->setColor(0);
            L_var1->fillRect(0, 0, o::b_i, o::c_i);
         } else {
            if ((!o::b_z)) {
               return;
            }
            int32_t L_var8 = o::a_m->a_ii_i(0, o::j_i);
            while ((L_var8 != 0)) {
               {
                  (L_var8 = o::a_m->a_ii_i(L_var8, o::j_i));
               }
            }
         }
         L_var1->setClip(0, 0, o::b_i, o::c_i);
         for (int32_t L_var7 = 0; (L_var7 < 3); (L_var7++)) {
            {
               JString L_var9{};
               if ((((L_var9 = o::b_AString[L_var7])) != nullptr)) {
                  int32_t L_var2 = o::c_i_i(L_var7);
                  int32_t L_var3 = 0;
                  int32_t L_var4 = 0;
                  if ((((L_var2 & 4)) == 4)) {
                     (L_var3 = 2);
                  }
                  if ((((L_var2 & 8)) == 8)) {
                     (L_var3 = jwrap32(jwint(o::b_i) - jwint(2)));
                  }
                  if ((((L_var2 & 1)) == 1)) {
                     (L_var3 = jshr(int32_t(o::b_i),1));
                  }
                  if ((((L_var2 & 16)) == 16)) {
                     (L_var4 = 2);
                  }
                  if ((((L_var2 & 32)) == 32)) {
                     (L_var4 = jwrap32(jwint(o::c_i) - jwint(2)));
                  }
                  if ((((L_var2 & 2)) == 2)) {
                     (L_var4 = jshr(int32_t(o::c_i),1));
                  }
                  (m::__ci(), m::a_Stringiiii_v(L_var9, o::c_Ai[L_var7], L_var3, L_var4, L_var2));
               }
            }
         }
      }
      catch (JThrowable& L_var5) {
      }
   }
}
int32_t o::e_i_i(int32_t L_var0) {
   if ((L_var0 == (-7))) {
      return 5;
   } else {
      if ((L_var0 == (-6))) {
         return 6;
      } else {
         if ((L_var0 == (-5))) {
            return 7;
         } else {
            {
               switch (L_var0) {
               case 35:
               {
                  return 21;
               }
               case 36:
               case 37:
               case 38:
               case 39:
               case 40:
               case 41:
               case 43:
               case 44:
               case 45:
               case 46:
               case 47:
               default:
               {
                  try {
                     (L_var0 = o::a_o->getGameAction(L_var0));
                  }
                  catch (JIllegalArgumentException& L_var1) {
                     return (-1);
                  }
                  {
                     switch (L_var0) {
                     case 1:
                     {
                        return 1;
                     }
                     case 2:
                     {
                        return 3;
                     }
                     case 3:
                     case 4:
                     default:
                     {
                        return (-1);
                     }
                     case 5:
                     {
                        return 4;
                     }
                     case 6:
                     {
                        return 2;
                     }
                     }
                  }
               }
               case 42:
               {
                  return 20;
               }
               case 48:
               {
                  return 10;
               }
               case 49:
               {
                  return 11;
               }
               case 50:
               {
                  return 12;
               }
               case 51:
               {
                  return 13;
               }
               case 52:
               {
                  return 14;
               }
               case 53:
               {
                  return 15;
               }
               case 54:
               {
                  return 16;
               }
               case 55:
               {
                  return 17;
               }
               case 56:
               {
                  return 18;
               }
               case 57:
               {
                  return 19;
               }
               }
            }
         }
      }
   }
}
void o::d_ii_v(int32_t L_var0, int32_t L_var1) {
   if ((!o::k_z)) {
      if (o::b_z) {
         try {
            if ((((L_var1 & 8)) == 8)) {
               (L_var0 = o::e_i_i(L_var0));
            }
            if ((o::s_i == 2)) {
               if ((L_var0 == 15)) {
                  (L_var0 = 7);
               } else {
                  if ((L_var0 == 12)) {
                     (L_var0 = 1);
                  } else {
                     if ((L_var0 == 14)) {
                        (L_var0 = 3);
                     } else {
                        if ((L_var0 == 18)) {
                           (L_var0 = 2);
                        } else {
                           if ((L_var0 == 16)) {
                              (L_var0 = 4);
                           }
                        }
                     }
                  }
               }
            }
            if (((o::s_i == 3) && ((((L_var0 >= 10) && (L_var0 <= 21)) || (L_var0 == 21))))) {
               if ((((L_var1 & 1)) == 1)) {
                  if ((L_var0 == 21)) {
                     return;
                  }
                  int64_t L_var4{};
                  if (((([&]() { auto __l1165 = ((L_var4 = JSystem::currentTimeMillis())); auto __r1166 = o::c_l; return jwrap64(jwlong(__l1165) - jwlong(__r1166)); }()) < (int64_t)700LL) && (L_var0 == o::x_i))) {
                     (o::y_i++);
                  } else {
                     (o::y_i = 0);
                  }
                  (L_var1 = jwrap32(jwint(L_var0) - jwint(10)));
                  if (((o::a_AAc[L_var1].length() != 0) && (L_var1 >= 0))) {
                     (o::c_l = L_var4);
                     (o::x_i = L_var0);
                     char16_t L_var3 = o::a_AAc[L_var1][jrem(int32_t(o::y_i),int32_t(o::a_AAc[L_var1].length()))];
                     if (((((L_var0 != o::z_i) || (L_var3 != o::a_c))) && (!o::l_z))) {
                        (o::z_i = L_var0);
                        (o::a_c = L_var3);
                        (o::d_l = JSystem::currentTimeMillis());
                        (o::l_z = true);
                     }
                     return;
                  }
               } else {
                  if ((((L_var1 & 2)) == 2)) {
                     if ((((L_var0 >= 10) && (L_var0 <= 19)) && (([&]() { auto __l1167 = JSystem::currentTimeMillis(); auto __r1168 = o::c_l; return jwrap64(jwlong(__l1167) - jwlong(__r1168)); }()) > (int64_t)1200LL))) {
                        (o::y_i = 0);
                        (o::c_l = (int64_t)0LL);
                     }
                     o::k_i_v(L_var0);
                  }
               }
            } else {
               if ((((L_var1 & 1)) == 1)) {
                  if ((o::w_i < 20)) {
                     (o::f_Ai[o::w_i] = L_var0);
                     (o::w_i++);
                  }
                  if ((L_var0 != (-1))) {
                     (o::t_i |= jshl(int32_t(1),L_var0));
                     (o::u_i |= jshl(int32_t(1),L_var0));
                     return;
                  }
               } else {
                  if (((((L_var1 & 2)) == 2) && (L_var0 != (-1)))) {
                     (o::t_i &= (~(jshl(int32_t(1),L_var0))));
                  }
               }
            }
         }
         catch (JThrowable& L_var6) {
         }
      }
   }
}
void o::k_i_v(int32_t L_var0) {
   if (((L_var0 == o::z_i) && o::l_z)) {
      (o::l_z = false);
      (o::z_i = 999);
      (o::a_c = char16_t(u' '));
   }
}
void o::keyPressed(int32_t L_var1) {
   o::d_ii_v(L_var1, 9);
}
void o::keyReleased(int32_t L_var1) {
   o::d_ii_v(L_var1, 10);
}
void o::showNotify() {
   o::h_i_v(5);
}
void o::hideNotify() {
   o::h_i_v(4);
}
void o::paint(JGraphics L_var1) {
   this->b_Graphics_v(L_var1);
}
void o::commandAction(JCommand L_var1, JDisplayable L_var2) {
}
void p::__clinit() {
   __inited = true;
   j::__ci();
}
p::p() {
   (this->c_b = ((int8_t)(2)));
}
int32_t p::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   (L_var2 = j::a_Abi_i(L_var1, L_var2));
   ([&]() -> decltype(auto) { auto& __a1171 = this->a_i; auto __v1172 = jwrap32(jwint(((int16_t)((([&]() { auto __l1169 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1170 = (L_var1[(L_var2++)] & 255); return (__l1169 | __r1170); }()))))) + jwint(1)); return (__a1171 = __v1172); }());
   ([&]() -> decltype(auto) { auto& __a1175 = this->b_i; auto __v1176 = ((int16_t)((([&]() { auto __l1173 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1174 = (L_var1[(L_var2++)] & 255); return (__l1173 | __r1174); }())))); return (__a1175 = ((int32_t)(__v1176))); }());
   int32_t L_var3 = (L_var1[(L_var2++)] & 255);
   int32_t L_var4 = (L_var1[(L_var2++)] & 255);
   int32_t L_var5 = (L_var1[(L_var2++)] & 255);
   int32_t L_var6 = (L_var1[(L_var2++)] & 255);
   (this->c_i = (((jshl(int32_t(L_var3),24) | jshl(int32_t(L_var4),16)) | jshl(int32_t(L_var5),8)) | L_var6));
   (this->c_Ai = newArr<int32_t>(this->a_i));
   (this->d_Ai = newArr<int32_t>(this->a_i));
   (this->e_Ai = newArr<int32_t>(this->a_i));
   (this->f_Ai = newArr<int32_t>(this->a_i));
   (this->a_As = newArr<int16_t>(this->b_i));
   int32_t L_var27 = ((int32_t)(L_var1[(L_var2++)]));
   int32_t L_var29 = ((int32_t)(((int16_t)((([&]() { auto __l1177 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1178 = (L_var1[(L_var2++)] & 255); return (__l1177 | __r1178); }()))))));
   (L_var2 = j::a_AiiiAbii_i(this->c_Ai, jwrap32(jwint(this->a_i) - jwint(1)), L_var29, L_var1, L_var2, L_var27));
   (L_var29 = ((int32_t)(((int16_t)((([&]() { auto __l1179 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1180 = (L_var1[(L_var2++)] & 255); return (__l1179 | __r1180); }())))))));
   (L_var2 = j::a_AiiiAbii_i(this->d_Ai, jwrap32(jwint(this->a_i) - jwint(1)), L_var29, L_var1, L_var2, L_var27));
   (L_var27 = ((int32_t)(L_var1[(L_var2++)])));
   (L_var2 = j::a_AsiiiAbii_i(this->a_As, this->b_i, 0, 1, L_var1, L_var2, L_var27));
   (this->c_Ai[jwrap32(jwint(this->a_i) - jwint(1))] = this->c_Ai[0]);
   (this->d_Ai[jwrap32(jwint(this->a_i) - jwint(1))] = this->d_Ai[0]);
   ([&]() -> decltype(auto) { auto& __a1183 = this->a_s; auto __v1184 = ((int16_t)((([&]() { auto __l1181 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1182 = (L_var1[(L_var2++)] & 255); return (__l1181 | __r1182); }())))); return (__a1183 = __v1184); }());
   this->a__v();
   return L_var2;
}
void p::a__v() {
   j::a__v();
   for (int32_t L_var1 = 0; (L_var1 < this->c_Ai.length()); (L_var1++)) {
      {
         if ((this->c_Ai[L_var1] < this->e_i)) {
            (this->e_i = this->c_Ai[L_var1]);
         }
         if ((this->c_Ai[L_var1] > this->g_i)) {
            (this->g_i = this->c_Ai[L_var1]);
         }
      }
   }
   for (int32_t L_var2 = 0; (L_var2 < this->d_Ai.length()); (L_var2++)) {
      {
         if ((this->d_Ai[L_var2] < this->f_i)) {
            (this->f_i = this->d_Ai[L_var2]);
         }
         if ((this->d_Ai[L_var2] > this->h_i)) {
            (this->h_i = this->d_Ai[L_var2]);
         }
      }
   }
}
void p::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   p* L_var13 = this;
   if (this->g_z) {
      this->a_d_v(j::a_d);
      int32_t L_var5 = L_var3->c_i;
      int32_t L_var6 = L_var3->f_i;
      (L_var3->c_i = 0);
      (L_var3->f_i = 0);
      (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
      (L_var3->c_i = L_var5);
      (L_var3->f_i = L_var6);
      for (int32_t L_var4 = 0; (L_var4 < L_var13->a_i); (L_var4++)) {
         {
            (d::__ci(),d::a_d)->a_ii_v(L_var13->c_Ai[L_var4], L_var13->d_Ai[L_var4]);
            (L_var13->e_Ai[L_var4] = jshr(int32_t((d::__ci(),d::g_i)),16));
            (L_var13->f_Ai[L_var4] = jshr(int32_t((d::__ci(),d::h_i)),16));
         }
      }
      (L_var13->g_z = false);
   }
   int32_t L_var14 = jwrap32(jwint((o::__ci(),o::b_i)) - jwint(1));
   int32_t L_var16 = jwrap32(jwint((o::__ci(),o::c_i)) - jwint(1));
   int32_t L_var17 = jshr(int32_t(L_var3->c_i),16);
   int32_t L_var15 = jshr(int32_t(L_var3->f_i),16);
   L_var1->setColor((m::__ci(), m::c_i_i(this->c_i)));
   for (int32_t L_var18 = 0; (L_var18 < this->b_i); (L_var18 += 3)) {
      {
         int32_t L_var7 = ((int32_t)(this->a_As[L_var18]));
         int32_t L_var8 = ((int32_t)(this->a_As[jwrap32(jwint(L_var18) + jwint(1))]));
         int32_t L_var9 = ((int32_t)(this->a_As[jwrap32(jwint(L_var18) + jwint(2))]));
         int32_t L_var10 = jwrap32(jwint(this->e_Ai[L_var7]) + jwint(L_var17));
         int32_t L_var11 = jwrap32(jwint(this->e_Ai[L_var8]) + jwint(L_var17));
         int32_t L_var12 = jwrap32(jwint(this->e_Ai[L_var9]) + jwint(L_var17));
         (L_var7 = jwrap32(jwint(this->f_Ai[L_var7]) + jwint(L_var15)));
         (L_var8 = jwrap32(jwint(this->f_Ai[L_var8]) + jwint(L_var15)));
         (L_var9 = jwrap32(jwint(this->f_Ai[L_var9]) + jwint(L_var15)));
         if ((((((((L_var10 >= 0) || (L_var11 >= 0)) || (L_var12 >= 0))) && ((((L_var7 >= 0) || (L_var8 >= 0)) || (L_var9 >= 0)))) && ((((L_var10 <= L_var14) || (L_var11 <= L_var14)) || (L_var12 <= L_var14)))) && ((((L_var7 <= L_var16) || (L_var8 <= L_var16)) || (L_var9 <= L_var16))))) {
            L_var1->fillTriangle(L_var10, L_var7, L_var11, L_var8, L_var12, L_var9);
         }
      }
   }
}
void q::__clinit() {
   __inited = true;
   a_q = nullptr;
   a_DataInputStream = nullptr;
   JString L_var0 = JSystem::getProperty(JS(u"microedition.platform"));
   bool L_var1 = false;
   JStringBuffer L_var2 = JStringBuffer::make();
   if ((q::a_q == nullptr)) {
      (q::a_q = (q::__ci(), new q()));
   }
   {
   {
      JInputStream L_var3{};
      if ((((L_var3 = jgetclass()->getResourceAsStream(JS(u"/META-INF/MANIFEST.MF")))) != nullptr)) {
         {
         while (true) {
            {
               while (true) {
                  {
                     try {
                        int32_t L_var4{};
                        if ((((L_var4 = L_var3->read())) < 0)) {
                           goto label78_brk;
                        }
                        if ((((char16_t)(L_var4)) != char16_t(u'\r'))) {
                           if ((((char16_t)(L_var4)) != char16_t(u'\n'))) {
                              L_var2->append(((char16_t)(L_var4)));
                           } else {
                              if ((!L_var2->toString().trim().startsWith(JS(u"Nokia-Platform:")))) {
                                 L_var2->delete_(0, L_var2->length());
                              } else {
                                 L_var2->append(q::a_InputStream_StringBuffer(L_var3));
                                 break;
                              }
                           }
                        }
                     }
                     catch (JIOException& L_var6) {
                     }
                  }
               }
               JString L_var11 = L_var2->toString().trim().substring(15);
               JVector L_var7 = JVector::make();
               bool L_var8 = false;
               int32_t L_var9{};
               while ((((L_var9 = L_var11.indexOf(JS(u"@")))) != (-1))) {
                  {
                     L_var7->addElement(L_var11.substring(0, L_var9));
                     (L_var11 = ([&]() -> decltype(auto) { auto __p1185 = jwrap32(jwint(L_var9) + jwint(1)); auto __p1186 = L_var11.length(); return L_var11.substring(__p1185, __p1186); }()));
                  }
               }
               L_var7->addElement(L_var11);
               int32_t L_var10 = 0;
               while (true) {
                  {
                     if (([&]() { auto __l1187 = L_var10; auto __r1188 = L_var7->size(); return (__l1187 >= __r1188); }())) {
                        goto label69_brk;
                     }
                     JString L_var5 = (jcast<JString>(L_var7->elementAt(L_var10))).trim();
                     if (q::a_StringStringii_z(L_var0, L_var5, 0, 0)) {
                        (L_var1 = true);
                        goto label69_brk;
                     }
                     (L_var10++);
                  }
               }
            }
            label69_cont:;
         }
         }
         label69_brk:;
      }
      if ((!L_var1)) {
         JSystem::exit(0);
      }
   }
   }
   label78_brk:;
   (q::a_String = nullptr);
}
q::q() {
}
JString q::a_StringStringString_String(JString L_var0, JString L_var1, JString L_var2) {
   int32_t L_var3{};
   do {
      {
         if ((((L_var3 = L_var0.indexOf(L_var1))) >= 0)) {
            (L_var0 = ([&]() { auto __l1193 = ([&]() { auto __l1189 = L_var0.substring(0, L_var3); auto __r1190 = L_var2; return jcat(__l1189,__r1190); }()); auto __r1194 = L_var0.substring(([&]() { auto __l1191 = L_var3; auto __r1192 = L_var1.length(); return jwrap32(jwint(__l1191) + jwint(__r1192)); }())); return jcat(__l1193,__r1194); }()));
         }
      }
   } while ((L_var3 >= 0));
   return L_var0;
}
JString q::a_i_String(int32_t L_var0) {
   return q::a_iAString_String(L_var0, nullptr);
}
JString q::a_iAString_String(int32_t L_var0, Arr<JString> L_var1) {
   if ((q::a_String == nullptr)) {
      (q::a_String = JSystem::getProperty(JS(u"microedition.locale")));
   }
   try {
      if ((q::a_q == nullptr)) {
         (q::a_q = (q::__ci(), new q()));
      }
      if ((q::a_DataInputStream == nullptr)) {
         JInputStream L_var2{};
         if ((((L_var2 = jgetclass()->getResourceAsStream(jcat(JS(u"/lang."),q::a_String)))) == nullptr)) {
            (L_var2 = jgetclass()->getResourceAsStream(JS(u"/lang.xx")));
         }
         if ((L_var2 == nullptr)) {
            return JS(u"X");
         }
         ((q::a_DataInputStream = JDataInputStream::make(L_var2)))->mark(512);
      }
      q::a_DataInputStream->skipBytes(jshl(int32_t(L_var0),1));
      int32_t L_var6 = q::a_DataInputStream->readUnsignedShort();
      q::a_DataInputStream->skipBytes(jwrap32(jwint(jwrap32(jwint(L_var6) - jwint((jshl(int32_t(L_var0),1))))) - jwint(2)));
      JString L_var5 = q::a_DataInputStream->readUTF();
      if ((!q::a_DataInputStream->markSupported())) {
         q::a_DataInputStream->close();
         (q::a_DataInputStream = nullptr);
      } else {
         try {
            q::a_DataInputStream->reset();
         }
         catch (JIOException& L_var3) {
            q::a_DataInputStream->close();
            (q::a_DataInputStream = nullptr);
         }
      }
      if ((L_var1 != nullptr)) {
         if ((L_var1.length() == 1)) {
            (L_var5 = q::a_StringStringString_String(L_var5, JS(u"%U"), L_var1[0]));
         } else {
            for (int32_t L_var7 = 0; (L_var7 < L_var1.length()); (L_var7++)) {
               {
                  (L_var5 = q::a_StringStringString_String(L_var5, jcat(jcat(JS(u"%"),L_var7),JS(u"U")), L_var1[L_var7]));
               }
            }
         }
      }
      return L_var5;
   }
   catch (JIOException& L_var4) {
      (q::a_DataInputStream = nullptr);
      return JS(u"E");
   }
}
bool q::a_StringStringii_z(JString L_var0, JString L_var1, int32_t L_var2, int32_t L_var3) {
   while ((([&]() { auto __l1195 = L_var2; auto __r1196 = L_var0.length(); return (__l1195 != __r1196); }()) || ([&]() { auto __l1197 = L_var3; auto __r1198 = L_var1.length(); return (__l1197 != __r1198); }()))) {
      {
         if ((([&]() { auto __l1199 = L_var2; auto __r1200 = L_var0.length(); return (__l1199 == __r1200); }()) || ([&]() { auto __l1201 = L_var3; auto __r1202 = L_var1.length(); return (__l1201 == __r1202); }()))) {
            return false;
         }
         {
            switch (L_var1.charAt(L_var3)) {
            case char16_t(u'*'):
            {
               if (([&]() { auto __l1203 = L_var3; auto __r1204 = jwrap32(jwint(L_var1.length()) - jwint(1)); return (__l1203 == __r1204); }())) {
                  return true;
               }
               if (q::a_StringStringii_z(L_var0, L_var1, L_var2, jwrap32(jwint(L_var3) + jwint(1)))) {
                  return true;
               }
               (L_var2++);
               break;
            }
            case char16_t(u'?'):
            {
               (L_var2++);
               (L_var3++);
               break;
            }
            default:
            {
               if (([&]() { auto __l1205 = L_var0.charAt(L_var2); auto __r1206 = L_var1.charAt(L_var3); return (__l1205 != __r1206); }())) {
                  return false;
               }
               (L_var2++);
               (L_var3++);
            }
            }
         }
      }
   }
   return true;
}
JStringBuffer q::a_InputStream_StringBuffer(JInputStream L_var0) {
   JStringBuffer L_var1 = JStringBuffer::make();
   try {
      if ((((char16_t)(L_var0->read())) != char16_t(u' '))) {
         return L_var1;
      }
      int32_t L_var2{};
      while ((((L_var2 = L_var0->read())) >= 0)) {
         {
            if ((((char16_t)(L_var2)) != char16_t(u'\r'))) {
               if ((((char16_t)(L_var2)) == char16_t(u'\n'))) {
                  L_var1->append(q::a_InputStream_StringBuffer(L_var0));
                  break;
               }
               L_var1->append(((char16_t)(L_var2)));
            }
         }
      }
   }
   catch (JIOException& L_var3) {
   }
   return L_var1;
}
void r::__clinit() {
   __inited = true;
   j::__ci();
}
r::r() {
   (this->c_b = ((int8_t)(5)));
}
int32_t r::a_Abi_i(Arr<int8_t> L_var1, int32_t L_var2) {
   (L_var2 = j::a_Abi_i(L_var1, L_var2));
   int32_t L_var3 = (L_var1[(L_var2++)] & 255);
   (this->c_As = newArr<int16_t>(L_var3));
   (this->d_As = newArr<int16_t>(L_var3));
   (this->a_As = newArr<int16_t>(L_var3));
   (this->b_As = newArr<int16_t>(L_var3));
   if ((L_var3 > 0)) {
      int32_t L_var4 = (L_var1[(L_var2++)] & 255);
      int32_t L_var5 = ((int32_t)(((int16_t)((([&]() { auto __l1207 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1208 = (L_var1[(L_var2++)] & 255); return (__l1207 | __r1208); }()))))));
      int32_t L_var6 = ((int32_t)(((int16_t)((([&]() { auto __l1209 = jshl(int32_t(L_var1[(L_var2++)]),8); auto __r1210 = (L_var1[(L_var2++)] & 255); return (__l1209 | __r1210); }()))))));
      if ((L_var4 > 0)) {
         (L_var2 = j::a_AsiiiAbii_i(this->c_As, L_var3, L_var5, 1, L_var1, L_var2, L_var4));
         (L_var2 = j::a_AsiiiAbii_i(this->d_As, L_var3, L_var6, 1, L_var1, L_var2, L_var4));
      } else {
         for (int32_t L_var15 = 0; (L_var15 < L_var3); (L_var15++)) {
            {
               (this->c_As[L_var15] = ((int16_t)(L_var5)));
               (this->d_As[L_var15] = ((int16_t)(L_var6)));
            }
         }
      }
      (L_var2 = j::a_AsiiiAbii_i(this->a_As, L_var3, 0, 1, L_var1, L_var2, 16));
      for (int32_t L_var16 = 0; (L_var16 < L_var3); (L_var16++)) {
         {
            (this->b_As[L_var16] = ((int16_t)((-1))));
         }
      }
   }
   return L_var2;
}
int32_t r::a_i_i(int32_t L_var0) {
   {
      switch (L_var0) {
      case 474:
      {
         return 150;
      }
      case 480:
      {
         return 150;
      }
      case 485:
      {
         return 150;
      }
      default:
      {
         return 0;
      }
      }
   }
}
void r::a__v() {
   j::a__v();
   for (int32_t L_var1 = 0; (L_var1 < this->a_As.length()); (L_var1++)) {
      {
         int32_t L_var2 = ([&]() { auto __l1211 = (jshl(int32_t((o::__ci(), o::a_ii_i(((int32_t)(this->a_As[L_var1])), 0))),16)); auto __r1212 = j::g_d->a_i; return jdiv(int32_t(__l1211),int32_t(__r1212)); }());
         int32_t L_var3 = ([&]() { auto __l1213 = (jshl(int32_t((o::__ci(), o::a_ii_i(((int32_t)(this->a_As[L_var1])), 1))),16)); auto __r1214 = j::g_d->a_i; return jdiv(int32_t(__l1213),int32_t(__r1214)); }());
         int32_t L_var4 = ([&]() { auto __l1215 = (jshl(int32_t((o::__ci(), o::a_ii_i(((int32_t)(this->a_As[L_var1])), 2))),16)); auto __r1216 = j::g_d->a_i; return jdiv(int32_t(__l1215),int32_t(__r1216)); }());
         int32_t L_var5 = ([&]() { auto __l1217 = (jshl(int32_t((o::__ci(), o::a_ii_i(((int32_t)(this->a_As[L_var1])), 3))),16)); auto __r1218 = j::g_d->a_i; return jdiv(int32_t(__l1217),int32_t(__r1218)); }());
         int32_t L_var8{};
         (L_var2 = ([&]() { auto __l1219 = ((L_var8 = jwrap32(jwint(this->c_As[L_var1]) - jwint(L_var4)))); auto __r1220 = L_var2; return jwrap32(jwint(__l1219) + jwint(__r1220)); }()));
         int32_t L_var9{};
         (L_var3 = ([&]() { auto __l1221 = ((L_var9 = jwrap32(jwint(this->d_As[L_var1]) - jwint((jwrap32(jwint(L_var3) - jwint(L_var5))))))); auto __r1222 = L_var3; return jwrap32(jwint(__l1221) + jwint(__r1222)); }()));
         if ((L_var8 < this->e_i)) {
            (this->e_i = L_var8);
         }
         if ((L_var2 > this->g_i)) {
            (this->g_i = L_var2);
         }
         if ((L_var9 < this->f_i)) {
            (this->f_i = L_var9);
         }
         if ((L_var3 > this->h_i)) {
            (this->h_i = L_var3);
         }
      }
   }
   (this->e_i = jshl(int32_t(this->e_i),16));
   (this->g_i = jshl(int32_t(this->g_i),16));
   (this->f_i = jshl(int32_t(this->f_i),16));
   (this->h_i = jshl(int32_t(this->h_i),16));
}
void r::d__v() {
   j::d__v();
   for (int32_t L_var1 = 0; (L_var1 < this->a_As.length()); (L_var1++)) {
      {
         if ((this->b_As[L_var1] > (-1))) {
            int32_t L_var2 = (o::__ci(),o::a_i);
            if ((this->a_As[L_var1] != 9999)) {
               (this->a_As[L_var1] = ((int16_t)((jwrap32(jwint(this->a_As[L_var1]) - jwint(L_var2))))));
            }
            if ((this->a_As[L_var1] <= 0)) {
               if ((this->b_As[L_var1] != 474)) {
                  this->j__v();
                  return;
               }
               if ((this->a_As[L_var1] < (-1500))) {
                  this->j__v();
                  return;
               }
            }
         }
      }
   }
}
void r::a_GraphicsDirectGraphicsd_v(JGraphics L_var1, JDirectGraphics L_var2, d* L_var3) {
   this->a_d_v(j::a_d);
   (d::__ci(), d::a_ddd_v(L_var3, j::a_d, (d::__ci(),d::a_d)));
   for (int32_t L_var14 = 0; (L_var14 < this->a_As.length()); (L_var14++)) {
      {
         (d::__ci(),d::a_d)->a_ii_v(jshl(int32_t(this->c_As[L_var14]),16), jshl(int32_t(this->d_As[L_var14]),16));
         int32_t L_var15 = jshr(int32_t((d::__ci(),d::g_i)),16);
         int32_t L_var4 = jshr(int32_t((d::__ci(),d::h_i)),16);
         if ((this->b_As[L_var14] <= (-1))) {
            (o::__ci(), o::a_iii_v(L_var15, L_var4, ((int32_t)(this->a_As[L_var14]))));
         } else {
            int32_t L_var5 = 0;
            int32_t L_var6 = 0;
            if ((this->a_As[L_var14] != 9999)) {
               (L_var6 = ((int32_t)(this->a_As[L_var14])));
            } else {
               (L_var6 = (m::__ci(),m::a_i));
            }
            if (((this->a_As[L_var14] <= 0) && (this->b_As[L_var14] == 474))) {
               (L_var6 = 1);
               (L_var5 = jshl(int32_t(((jdiv(int32_t(jwrap32(jwint(jmath_abs<int32_t>(this->a_As[L_var14])) * jwint(255))),int32_t(1500)) & 0xFF))),24));
            }
            int32_t L_var7 = jshr(int32_t((d::__ci(),d::g_i)),16);
            int32_t L_var8 = jshr(int32_t((d::__ci(),d::h_i)),16);
            JGraphics L_var9 = (o::__ci(), o::a__Graphics());
            if ((L_var5 != 0)) {
               (m::__ci(),m::b_Graphics)->setColor(255);
               ([&]() -> decltype(auto) { auto __p1223 = 0; auto __p1224 = 0; auto __p1225 = (m::__ci(),m::b_Image)->getWidth(); auto __p1226 = (m::__ci(),m::b_Image)->getHeight(); return (m::__ci(),m::b_Graphics)->fillRect(__p1223, __p1224, __p1225, __p1226); }());
               (L_var15 = jshr(int32_t((m::__ci(),m::b_Image)->getWidth()),1));
               (L_var4 = (m::__ci(),m::b_Image)->getHeight());
               (L_var1 = (m::__ci(),m::b_Graphics));
               (o::__ci(), o::a_Graphics_v((m::__ci(),m::b_Graphics)));
            }
            int32_t L_var12 = (o::__ci(), o::b_i_i(((int32_t)(this->b_As[L_var14]))));
            int32_t L_var10 = 0;
            if ((this->a_As[L_var14] != 9999)) {
               int32_t L_var21{};
               int32_t L_var10000{};
               {
                  switch ((L_var21 = ((int32_t)(this->b_As[L_var14])))) {
                  case 474:
                  {
                     (L_var10000 = 750);
                     break;
                  }
                  case 480:
                  case 485:
                  {
                     (L_var10000 = 9999);
                     break;
                  }
                  default:
                  {
                     (L_var10000 = 0);
                  }
                  }
               }
               (L_var10 = ([&]() { auto __l1229 = ([&]() { auto __l1227 = (jwrap32(jwint(L_var10000) - jwint(L_var6))); auto __r1228 = r::a_i_i(((int32_t)(this->b_As[L_var14]))); return jdiv(int32_t(__l1227),int32_t(__r1228)); }()); auto __r1230 = L_var12; return jrem(int32_t(__l1229),int32_t(__r1230)); }()));
            } else {
               (L_var10 = ([&]() { auto __l1233 = ([&]() { auto __l1231 = L_var6; auto __r1232 = r::a_i_i(((int32_t)(this->b_As[L_var14]))); return jdiv(int32_t(__l1231),int32_t(__r1232)); }()); auto __r1234 = L_var12; return jrem(int32_t(__l1233),int32_t(__r1234)); }()));
            }
            if ((L_var10 > jwrap32(jwint(L_var12) - jwint(1)))) {
               (L_var10 = jwrap32(jwint(L_var12) - jwint(1)));
            }
            (o::__ci(), o::b_iiii_v(L_var15, L_var4, ((int32_t)(this->b_As[L_var14])), L_var10));
            if ((L_var5 != 0)) {
               (o::__ci(), o::a_Graphics_v(L_var9));
               ([&]() -> decltype(auto) { auto __p1235 = (m::__ci(),m::b_Ai); auto __p1236 = 0; auto __p1237 = (m::__ci(),m::b_Image)->getWidth(); auto __p1238 = 0; auto __p1239 = 0; auto __p1240 = (m::__ci(),m::b_Image)->getWidth(); auto __p1241 = (m::__ci(),m::b_Image)->getHeight(); return (m::__ci(),m::b_Image)->getRGB(__p1235, __p1236, __p1237, __p1238, __p1239, __p1240, __p1241); }());
               int32_t L_var13 = 0;
               for (int32_t L_var16 = 0; ([&]() { auto __l1242 = L_var16; auto __r1243 = (m::__ci(),m::b_Image)->getHeight(); return (__l1242 < __r1243); }()); (L_var16++)) {
                  {
                     for (int32_t L_var18 = 0; ([&]() { auto __l1244 = L_var18; auto __r1245 = (m::__ci(),m::b_Image)->getWidth(); return (__l1244 < __r1245); }()); (L_var18++)) {
                        {
                           if (((m::__ci(),m::b_Ai)[L_var13] == (-16776961))) {
                              ((m::__ci(),m::b_Ai)[L_var13] = 0);
                           } else {
                              ((m::__ci(),m::b_Ai)[L_var13] = jwrap32(jwint((m::__ci(),m::b_Ai)[L_var13]) - jwint(L_var5)));
                           }
                           (L_var13++);
                        }
                     }
                  }
               }
               int32_t L_var17 = ([&]() { auto __l1246 = L_var7; auto __r1247 = (jshr(int32_t((m::__ci(),m::b_Image)->getWidth()),1)); return jwrap32(jwint(__l1246) - jwint(__r1247)); }());
               (L_var4 = ([&]() { auto __l1248 = L_var8; auto __r1249 = (m::__ci(),m::b_Image)->getHeight(); return jwrap32(jwint(__l1248) - jwint(__r1249)); }()));
               ([&]() -> decltype(auto) { auto __p1250 = (m::__ci(),m::b_Ai); auto __p1251 = 0; auto __p1252 = (m::__ci(),m::b_Image)->getWidth(); auto __p1253 = L_var17; auto __p1254 = L_var4; auto __p1255 = (m::__ci(),m::b_Image)->getWidth(); auto __p1256 = (m::__ci(),m::b_Image)->getHeight(); auto __p1257 = true; return (o::__ci(), o::a__Graphics())->drawRGB(__p1250, __p1251, __p1252, __p1253, __p1254, __p1255, __p1256, __p1257); }());
            }
         }
      }
   }
}
